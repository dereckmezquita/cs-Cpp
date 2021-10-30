# Introduction to `C++` <img src="./figures/project-logo.png" width="100" align="right">

## About this course

The point of this course is understanding the basics and some advances concepts in `C++`. For ease of use and presentation `.Rmd` documents are used to produce this course. 

A custom `C++` engine is defined for this course. Compiles chunks to an executable, runs programme and returns the stdout to the `.Rmd` document. In some cases with `Rcpp` as an interface to `C++` when useful such as for plotting etc.

Some conventions: 

1. We will always use base 0 counting; the standard in `C++`.
1. `Rcpp.h` libraries are avoided in favour of the standard `C++` headers.
1. Code will more often than not be written in a function body; allows compilation and use in `R`'s context.

Use of `Rcpp.h` libraries will be kept to a minimum and information on compilation and using `C++` outside the context of `R` will be detailed.

Let's start with something simple; demonstrate that we can indeed write and compile `C++` in this context.

Here is a function which generates the Fibonacci sequence to `n` elements.


```cpp
# include <Rcpp.h>
using namespace Rcpp;

// 0, 1, 1, 2, 3, 5, 8, 13

// [[Rcpp::export]]
NumericVector fibonacci_cpp(int n) {
	NumericVector vec(n);
	
	vec[1] = 1;
	for(int i = 1; i < n; i++) {
		vec[i + 1] = vec[i - 1] + vec[i];
	}
	
	return vec;
}
```


```r
fibonacci_cpp(20)
```

```
##  [1]    0    1    1    2    3    5    8   13   21   34   55   89  144  233  377
## [16]  610  987 1597 2584 4181
```

## About `C++`

`C++` is a language invented by Bjarne Stroustrup in 1979. It is based on the `C` language and can be summarised as `C` with classes; object oriented programming.

`C++` is a low level, compiled, and powerful language. `C++` has become ubiquitous over the years and virtually all systems support compiling and running compiled `C++` code.

Printing "hello world" in typical `C++` would look something like this:


```cpp
#include <iostream>

int main() {
  std::cout << "Hello World!" << std::endl;
}
```

```
## Hello World!
```

`C++` is written in files with a `.cpp` extension. The output you see above was generated with our custom chunk engine, you can find the standalone code again in the "./cpp/" directory.

## Anatomy of a `C++` programme

A programme written in `C++` is typically structured as such:

Libraries are just code files that have been pre-written and offer some kind of utility. These typically end with a `.h` extension which stands for "header" as they are included at the top of a programme.

**Indeed** `C++` is executed in a linear fashion from first line to last.

Libraries are included at the top of a programme with the syntax: `#include <iostream>`.

Libraries can be stored locally to a project or on a system level. Libraries can be written by anyone; you could write helper functions and have it stored locally to your project.

Some libraries have become so common that they are stored in a single location for a computer. These can be included using the brackets `<name of library>` would do it. In the case that you want to include a locally stored header file you would use double quotes `"name of file"`.

A `main` function is always included in the programme and always returns an `int` (integer). This is because a success and failure to run is denoted with `0`/`1`.

A basic `C++` document would like this; note the function structure - parenthesis and curlies.

**Note**: comments are written with `//` or for multi-line between `/* comment here */`.


```cpp
#include <iostream> // library

int main() { // declare the type returned; and main function
	// do something
}
```

In our previous example we wrote: `std::cout << "Hello world!"`. This comes from the `iostream` library, the `std` signals that we're getting the `cout` function from that library. Finally, `<<` is an operator that pases the right hand statement as an input to the left hand.

**Important: ALL* lines in `C++` must be ended with a semi-colon - ;**. All statements that is. *In some cases like the end curly of a function we do not for example.


## Workflow

As stated before `C++` is a compiled language. This means we will often follow this routine of: 

1. Write programme.
1. Save programme.
1. Compile programme.
	1. If error; read error, go back to step 1.
1. Execute programme.
	1. If error; read error, go back to step 1.

So I previously showed you what some of the code looks like. Why don't I explain to you some of the magic of how to actually compile a programme?

Indeed I've set this all up to be compiled from the code chunks in this document auto-magically with the use of a custom chunk engine. But it's super simple I promise. I'll explain myself.

So what you typically do as we said; is we write the progamme, let's write one:


```cpp
#include <iostream>

int main() {
	std::cout << "Hello world." << std::endl;
}
```

```
## Hello world.
```

Ok now save the above to a text file with the extension `.cpp`.

Now try this command in your terminal:


```bash
c++ programme_name.cpp -o programme_name
```

What are we doing there? Well we're compiling the programme from the text file, `-o` denotes the output name/location of the programme executable.

So let's try it:


```bash
echo '#include <iostream>

int main() {
	std::cout << "Hello world." << std::endl;
}' > ./cpp/hello.cpp

c++ ./cpp/hello.cpp -o ./cpp/hello
```

So now we should have our programme in the cpp directory let's take a look:


```bash
ls ./cpp/hello*

echo ''

cat ./cpp/hello.cpp

rm ./cpp/hello
```

```
## ./cpp/hello
## ./cpp/hello.cpp
## 
## #include <iostream>
## 
## int main() {
## 	std::cout << "Hello world." << std::endl;
## }
```

The text file is there and we've compiled it.

You may be thinking what is a compiled programme anyway? Why do we have to "compile"? Well a compiler is simply a translator. All it does is it takes our `C++` code and translates it to what's commonly referred to as machine code; assembly. Assembly is an extremely low level langauge that then can be directly compiled to binary which is the true language of any computer.

Indeed we are using `C++` code to talk to the comptuer. `C++` has features and concepts which allow us to more easily reason about what we want to do. 

If you want to write a bit of code that will be repeated n amount of times, in `C++` you would you something called a for loop. It looks a little something like this:


```cpp
int times = 100;
for(int i = 0; i < times; i++) {
	// do something
}
```

That is just the pure for loop. Doesn't look so intimidating does it? We will go over it more in detail later. But it's telling the computer do what's inside these brackets n times.

Let's you wanted to write assembly; baisically you would write a document and somewhere you'd tell it to JUMP back and repeat that code exactly with a new value for the iterator.

Why don't we write a loop, compile it and then try to take a look at what the assembly code looks like?

Here is a simple for loop, prints hello followed by the iterator 3 times.


```cpp
#include <iostream>

int main() {
	for(int i = 1; i <= 3; i++) {
		std::cout << "Hello " << i << std::endl;
	}
}
```

```
## Hello 1
## Hello 2
## Hello 3
```

Here we echo the code into a document and then compile it. Note the `-S` argument this tells the compiler to output assembly code.



```bash
echo 'int main() {
	int i;
	for(i = 1; i <= 3; i++) {
		int x = i;
	}
	
	return i;
}' > ./cpp/print_loop.cpp

c++ ./cpp/print_loop.cpp -o ./cpp/print_loop.asm -S
```

So now we've saved the code to a document, and compiled it. Let's take a look. 

**Note**: we've removed the print function and `<iostream>` from the code, as this includes a whole library which we don't really need. We just want to see what for loop looks like in assembly.


```bash
cat ./cpp/print_loop.asm
```

```asm
	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$0, -4(%rbp)
	movl	$1, -8(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$3, -8(%rbp)
	jg	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_1
LBB0_4:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
```


In summary from the above we can see how compiling works. You write some code then you use a compiler programme which translates your code to assembly/machine code.

The command would look something like this as we used above:


```bash
c++ ./cpp/print_loop.cpp -o ./cpp/print_loop -S
```


## Data structures and data types

You've seen the `int` prefix in the code I've shown you before. Notably before the main function. As I said before all variables and functions must have their type declared. Here we'll go over some data types and data structures of `C++`.

The basic data types we'll deal with are:

1. `int`: integer numbers.
1. `double`: floating point or decimal numbers.
1. `char`: individual characters.
1. `string`: a sequence of characters.
1. `bool`: a true/false or logical - 0 and 1 can also be used and cast to a `bool`.

Let's start with some numbers. You can declare a number first, then attribute a value. The important step with anything in `C++` is delcaring the type.


```cpp
#include <iostream>

int main() {
	int yeet; // declare yeet
	
	yeet = 1; // set equal to 1
	
	std::cout << yeet << std::endl;
	
	yeet = 2; // reset to 2
	
	std::cout << yeet << std::endl;
	
	int zoot = 131; // declare and set zoot
	
	std::cout << zoot << std::endl;
	
	int xoot = yeet + zoot; // declare and set xoot as sum of yeet + zoot
	
	std::cout << xoot << std::endl;
}
```

```
## 1
## 2
## 131
## 133
```

As you can see our variable `yeet` was declared and then set to equal 1, then subsequently equal to two and printed again.

**Note**: adding and arithmetic functions are as natural as +/-. Let's go over some maths yes?


## Arithmetic operators

In `C++` we have these as the following primitive arithmetic operators. Primitive because they are built into the language. You'll notice when you start needing more complex things such as n to the power of x you'll need some libraries.

- `+` addition.
- `-` subtraction.
- `*` multiplication.
- `/` division.
- `%` modulo; gets the remainder after the division.


```cpp
#include <iostream>

int main() {
	double score = 0;
	
	score = score + 20;
	std::cout << score << std::endl;
	
	score = score - 2;
	std::cout << score << std::endl;
	
	score = score * 3;
	std::cout << score << std::endl;
	
	score = score / 2;
	std::cout << score << std::endl;
	
	score = (int) score % 3;
	std::cout << score << std::endl;
}
```

```
## 20
## 18
## 54
## 27
## 0
```


Notice in the last operation I put `(int)` before taking modulo 3, this is something called type casing and we will learn more about it in the future.


## Project: quadratic maths

Let's put together what we've learned and make a programme that can solve the quaradtic formula. We'll also visualise what we do with some `R` code.

What even is the quadratic formula? Well a quadratic formula is a mathematical formula that allows you to find the solutions to a quadratic equation... 

I know, never define a word by using the word in the definition! Stick with me. A quadratic (meaning square or 4 in latin) equation is an equation that fits the form of:

<!-- $$
	ax ^ 2 + bx + c = 0
$$ --> 

<div align="center"><img style="padding: 15px; background: white;" src="svg/72GlKDpN1j.svg"></div>

1. `x` represents a variable.
1. `a, \, b, \, c` represent known numbers; `a \not= 0`.

What's going on in this equation to put things simply; you input a value for `x` and you get `y` back. You can then plot these!

Shifting the values of `a, \, b, \, c` is what defines different quadratic functions.

Note that if a is equal to zero then the equation simply becomes linear: 

<!-- $$
	bx + c = 0
$$ --> 

<div align="center"><img style="padding: 15px; background: white;" src="svg/wH1jrMS6BS.svg"></div>

Let's try it out and visualise. Here we define a function to calculate quadratic coordinates.

In order to get the values back for plotting we'll use `R`'s flavour of `C++`. We'll use `Rcpp`'s header file. Some other changes to note is no `main()` function, this is because the code is compiled by `Rcpp` the imported as a function to `R`.

Note the `using namespace Rcpp;` line; this means we can directly use the library without having to append everything with `Rcpp::`function_name. You can do the same thing with `std`.

Let's dissect the following code. This is 99% `C++` with a little bit of `Rcpp` in there just for getting back the function in here.


```cpp
#include <Rcpp.h>
#include <vector>

// [[Rcpp::export]]
std::vector<double> quadraticReturnY(std::vector<double> x, double a, double b, double c) {
	int n = x.size();
	
	std::vector<double> y(n);
	
	for(int i = 0; i < n; i++) {
		y[i] = (a * (x[i] * x[i])) + (b * x[i]) + c;
	}
	
	return y;
}
```

Here you see `<vector>`, what is a vector? A `vector` is a sort of super array defined in the standard library. It has some nice methods attached to it so we can get it's size easily like shown above for example: `x.size();`

Note that we are creating a `vector` with the following syntax: `std::vector<double>`. This is saying get the `vector` class from the standard library, and we're putting numbers inside this `vector` of type double.

What we're saying here is input to this function a `vector`, and some other variables. Do some calculations and return the `vector` of results y.

Let's then calculate the coordinates for a quadratic function of the following parameters:

1. `a = 1`
1. `b = 0`
1. `c = 0`


```r
a <- 1
b <- 0
c <- 0

x <- -20:20
y <- quadraticReturnY(x, a, b, c)

df <- data.frame(x = x, y = y)

head(df, 5)
```

```
##     x   y
## 1 -20 400
## 2 -19 361
## 3 -18 324
## 4 -17 289
## 5 -16 256
```


```r
if(df$y[which.max(abs(df$y))] > 0) {
	lim <- c(-15, NA)
} else {
	lim <- c(NA, 15)
}

ggplot2::ggplot(df, ggplot2::aes(x = x, y = y)) +
	ggplot2::geom_line() + 
	ggplot2::scale_y_continuous(limits = lim) +
	ggplot2::geom_hline(yintercept = c, linetype = "dashed", colour = "goldenrod", size = 1) +
	ggplot2::labs(title = "A classic quadratic plot", subtitle = stringr::str_interp('a = ${a}, b = ${b}, c = ${c}, x = [${min(x)} ... ${min(x)}]'))
```

<img src="./figures/cs-Cpp_files/figure-html/plot-classic-quadratic-1.png" style="display: block; margin: auto;" />

Notice how if we shift the values we move the plot around:


```r
a <- 1.4
b <- 40
c <- -4

x <- -30:20
y <- quadraticReturnY(x, a, b, c)

df <- data.frame(x = x, y = y)

ggplot2::ggplot(df, ggplot2::aes(x, y)) +
	ggplot2::geom_line() + 
	ggplot2::geom_hline(yintercept = -4, linetype = "dashed", colour = "goldenrod", size = 1) +
	ggplot2::labs(title = "A shifted quadratic plot", subtitle = stringr::str_interp('a = ${a}, b = ${b}, c = ${c}, x = [${min(x)} ... ${min(x)}]'))
```

<img src="./figures/cs-Cpp_files/figure-html/plot-shifted-quadratic-1.png" style="display: block; margin: auto;" />

So in the examples above we're asking the formula to give us back the `y` values for an array of `x`s.

Notice how the parabola at some point crosses the x axis. At this point y really does equal 0. This is called a solution, or a root to this equation. The equation is defined by the a, b and c constants in the context of the quadratic formula shown before.

There exists two roots, as a parabola has two arms, these are two solutions or two points where the arms intersect the x-axis. These points can be found by plugging these same constants into this formula.

Note if your parabola is shifted above the x-axis it's possible you have no real solutions.

Let's implement this formula for calculating a solution to the above shown parabola.

<!-- $$
	x = \frac{-b \pm \sqrt{b ^ 2 - 4ac}}{2a}
$$ --> 

<div align="center"><img style="padding: 15px; background: white;" src="svg/A3WlitXK3W.svg"></div>


```cpp
#include <Rcpp.h>
#include <math.h>
using namespace Rcpp;

// [[Rcpp::export]]
std::vector<double> quadraticRoots(double a, double b, double c) {
	
	std::vector<double> x(2);
	
	x[0] = (-b + std::sqrt((b * b) - (4 * a * c))) / (2 * a);
	x[1] = (-b - std::sqrt((b * b) -( 4 * a * c))) / (2 * a);
	
	return x;
}
```

Wonderful as we can see the roots or solutions to this quadratic formula are these! Note that if you were to plot these as points on the graph where these correspond to the x value (if y = 0) then you would find that these are indeed the points where the parabola's arms cross the x-axis.


```r
quadraticRoots(a, b, c)
```

```
## [1]   0.09965243 -28.67108100
```

Here's the same plot again, with the points we just calculated as red circles! Amazing!


```r
df2 <- data.frame(x = quadraticRoots(a, b, c), y = rep(0))

ggplot2::ggplot() +
	ggplot2::geom_line(data = df, ggplot2::aes(x, y)) +
	ggplot2::geom_point(data = df2, ggplot2::aes(x, y), colour = "red", size = 5, alpha = 0.5) +
	ggplot2::geom_hline(yintercept = -4, linetype = "dashed", colour = "goldenrod", size = 1) +
	ggplot2::labs(title = "A shifted quadratic plot", subtitle = stringr::str_interp('a = ${a}, b = ${b}, c = ${c}, x = [${min(x)} ... ${min(x)}]'))
```

<img src="./figures/cs-Cpp_files/figure-html/plot-quadratic-solutions-1.png" style="display: block; margin: auto;" />

