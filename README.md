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

**Note that ```arr``` must be a array with at least one element, but not pointer.**

### Initialization ```--```

- ```init(&var)``` will set every bytes of ```var``` to ```0```
	- if ```arr``` is name of a array ```init(&arr)``` will set every bytes of the space of array to ```0```

### Output ```--```

- ```__msg__(fmt, var)``` means output value of ```var``` as ```fmt``` format and name of ```var```,
where ```fmt``` is ```printf``` format string, and ```var``` will match the first ***format specifier***.  
	- ***e.g.***
		- ```__msg__("%d", 0)``` will output ```0 : 0```
		- if ```char *str = "abcd";```, ```__msg__("%s", str)``` will output ```str : abcd```

### ```enum``` operation ```--```

### Error code check ```--```
## [_.hh](_.hh)
## [ecp.hh](ecp.hh)
## [raii.hh](raii.hh)
## [uniq.hh](uniq.hh)
