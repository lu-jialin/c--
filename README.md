# C```--```
Minus minutia in C/C++ development

## Requirements

### Operating system

- Unix/Linux

### Language property

- Variable definition in block
> Just like: ```if(0) {void *p;}```
- Compiletime type inference is required. Such as ```typeof``` ```decltype```;

### Others

- POSIX ```errno``` is required;
- ```stderr``` is not redirected;

## [_.h](_.h)

### Type redefine

- Add ```_t``` suffix for base type;
- For type that can own sign, use ```#define``` but not ```typedef```.
So that words like ```unsigned int_t``` can be used;

### Interval determination ```--```

#### ```layout``` predication set

- if ```p``` is in ```(a,b)```, ```layout(a, p, b)``` is ```true```
- if ```p``` is in ```[a,b)```, ```_layout(a, p, b)``` is ```true```
- if ```p``` is in ```(a,b]```, ```layout_(a, p, b)``` is ```true```
- if ```p``` is in ```[a,b]```, ```_layout_(a, p, b)``` is ```true```

### Loop boundary ```--```

#### ```repeat``` operation set

- ```repeat(a, i, b)``` means ```i``` is integer in ```(a,b)```
- ```_repeat(a, i, b)``` means ```i``` is integer in ```[a,b)```
- ```repeat_(a, i, b)``` means ```i``` is integer in ```(a,b]```
- ```_repeat_(a, i, b)``` means ```i``` is integer in ```[a,b]```

A loop block wrapped by ```{}``` after ```repeat``` predication set will loop on the interval.
And ```i``` is a normal variable which value is current loop number, from ```a``` to ```b```
(if it was not changed in block).

#### Loop on a array

- ```#define elecntof(arr) sizeof(arr)/sizeof(*(arr))```
- ```iterate(p, arr)``` means ```p``` is a pointer of every elements of ```arr```

A loop block wrapped by ```{}``` after ```repeat``` predication set will loop on the interval.
And ```p``` is a normal pointer variable which value is current loop element in ```arr```,
from ```[0]``` to ```elecntof(arr)```
(if it was not changed in block).

<font style="color:red">Note that ```arr``` must be a array with at least one element, but not pointer.</font>

### Initialization ```--```

- ```init(&var)``` will set every bytes of ```var``` to ```0```
	- if ```arr``` is name of a array ```init(&arr)``` will set every bytes of the space of array to ```0```

### Output ```--```

- ```__msg__(fmt, var)``` means output value of ```var``` as ```fmt``` format and name of ```var```,
where ```fmt``` is ```printf``` format string, and ```var``` will match the first ***format specifier***.  
	- ***e.g.***
		- ```__msg__("%d", 0)``` will output ```0 : 0```
		- if ```char *str = "abcd";```, ```__msg__("%s", str)``` will output ```str : abcd```

<!-- ?{?

### ```enum``` operation ```--```

?}? -->

### Error code check ```--```

To use this funciton,
```MAIN_POSIX_ERRNO_CHK``` should be defined before return type of ```main()``` function.
like:

```c
MAIN_POSIX_ERRNO_CHK int
main(...)
{
	...
	return 0;
	...
}
```

And then some literary style can be used.

#### Base check

First of all, <font style="color:red">all error code should be assigned to posix ```errno```</font>.

Use ```__chk__``` after function that may set posix ```errno```, like:

```c
read(fd, &buf, size) __chk__;
```

If posix ```errno``` was set in ```read```, means that ```read``` is not successfully executed,
```__chk__``` after ```read``` will <font style="color:red">```abort``` the whole program</font>.

<font style="color:red">```__chk__``` would not do anything if macro ```NDEBUG``` is defined</font>.

#### Use ```__chk__``` in self define function or thirdparty interface

Because ```errno``` is global, when exception occur in a self define funcion,
set ```errno``` directly is suggested.
Or use return value or parameter to set error code to ```errno```:

- If function ```int foo()``` return the error code
	```c
	errno = foo() __chk__;
	```
- If function ```void foo(int *err)``` set the error code by parameter pointer
	```c
	foo(&errno) __chk__;
	```

#### Check without posix ```errno```

```__ext_chk__(err)``` can be used for checking any checkable variable.
If the value of ```err``` here is not ```0```, ```__ext_chk__``` will abort the program.

```__ext_chk__``` can be used anywhere ```__chk__``` can be used.

#### Skip error

##### ```__ignore_err__```

```__ignore_err__``` before ```__chk__``` can be used for skipping exception **ALL** befor here:

```c
write(fd, &buf, size) __ignore_err__ __chk__;
```

In upper code, ```__chk__``` will be **ALWAYS** ignore.

But if there are some process between ```__ignore_err__``` and ```__chk___```,
it still works:

```c
write(fd, &buf, size) __ignore_err__;
write(fd, ((char*)&buf) + size, size) __chk__;
```

In upper code, only the 2nd ```write``` will be checked.

##### ```__skip__```

```__skip__``` before ```__chk__``` can be used for skipping a type of exception:

```c
mkdir("./foo", 0777) __skip__(EEXIST) __chk__;
```
In upper code, if ```mkdir``` ```./foo``` failed,
but it is because the file ```./foo``` has been existed, ```__chk__``` will not abort the program.

One ```__skip__``` can only specify one value of error code,
but multiple ```__skip__``` can be used before one ```__chk___```:

```c
mkdir("./foo", 0777) __skip__(EEXIST) __skip__(EACCES) __chk__;
```

In upper code, error code ```EEXIST``` and ```EACCES``` will be ignore at the same ```__chk__```.

#### Self define error message

```__ext_msg__(msg)``` before ```__chk__``` can be used for output content of ```msg```
when ```__chk__``` abort.

Multiple ```__ext_msg__``` can be used befor one ```__chk__```,
but <font style="color:red">only the last one will be valid</font>.

```c
mkdir("./foo", 0777) __skip__(EEXIST) __skip__(EACCES) __ext_msg__("0777") __ext_msg__("./foo") __chk__;
```

In upper code, when ```mkdir``` failed, string ```"./foo"``` will be sent to ```stderr```,
except it was failed by ```EEXIST``` or ```EACCES```. ```__ext_msg__("0777")``` will be ignored.

<font style="color:red">Note that ```msg``` must be a C style string.</font>

## [_.hh](_.hh)
## [ecp.hh](ecp.hh)
## [raii.hh](raii.hh)
## [uniq.hh](uniq.hh)
