
.. index:: IEEE floating point 

.. _chap_ieee:

**************************
IEEE  부동 소수점 대수
**************************

.. note::

    번역중

이 단원에서는 부동 소수 표현을 검증하고, 
제어할 수 있는 함수들에 대해 기술합니다. 
이 단원에서 기술하는 함수들은 헤더 파일 
:file:`gsl_ieee_utils.h` 에 정의되어 있습니다


.. index::
   single: IEEE format for floating point numbers
   single: bias, IEEE format
   single: exponent, IEEE format
   single: sign bit, IEEE format
   single: mantissa, IEEE format

부동 소수점의 표현
========================================

IEEE 표준 이진 부동 소수점 대수에서는 단, 배정밀도의 이진 숫자 표현에 대해
정의하고 있습니다. 각 수는 3가지 부분으로 나뉘어 표현됩니다. 
부호( :math:`s` ), 지수(), 그리고 소수점()입니다. :math:`(s,E,f)` 표현의
실제 실수 값은 다음과 같이 주어집니다.

.. math::

   (-1)^s (1 \cdot ffff \dots)2^E

.. index::
   single: normalized form, IEEE format
   single: denormalized form, IEEE format

부호부는 0이거나 1입니다. 지수부의 하한 :math:`E_{min}` 과 상한 :math:`E_{max}` 는 
정밀도에 따라 달라집니다. 이 지수는 부호 없는 수 :math:`e` 로 변환될 수 있습니다.
이는 바이어스 지수부라 불리며, 바이어스 계수 :math:`bias` 를 더해 저장됩니다.

.. math::

   e = E + bias

배열 :math:`ffff \dots` 는 이진수의 자릿수를 나타냅니다. 
이 이진 자릿수는 정규화된 형태로 저장되는데, 지수를 조정해 처음 자리에 1이 오게합니다. 
정규화된 숫자는 처음 숫자가 항상 1이 온다고 암묵적으로 가정되기 때문에 저장되지 않습니다. 
만일, 숫자가 :math:`2^{E_{min}}` 보다 작다면, 처음 숫자가 0인 비 정규화된 형태로 저장됩니다.

.. math::

   (-1)^s (0 \cdot ffff \dots)2^E

The IEEE Standard for Binary Floating-Point Arithmetic

.. index::
   single: zero, IEEE format
   single: infinity, IEEE format

This allows gradual underflow down to 
:math:`2^{E_{min} - p}`
for :math:`p` bits of precision. 

0은 :math:`2^{E_{min}-1}` 형태로 특정 지수 값으로 정의됩니다.
같은 방식으로 무한대 :math:`\infty` 도 :math:`2^{E_{max}+1}` 로 정의됩니다.

.. index::
   single: single precision, IEEE format


32bit를 사용하는 단정밀도 숫자 표현은 다음과 같습니다.

::

  seeeeeeeefffffffffffffffffffffff
    
  s = sign bit, 1 bit
  e = exponent, 8 bits  (E_min=-126, E_max=127, bias=127)
  f = fraction, 23 bits

.. index::
   single: double precision, IEEE format

64bit를 사용하는 배정밀도 숫자 표현은 다음과 같습니다.

::

  seeeeeeeeeeeffffffffffffffffffffffffffffffffffffffffffffffffffff

  s = sign bit, 1 bit
  e = exponent, 11 bits  (E_min=-1022, E_max=1023, bias=1023)
  f = fraction, 52 bits

이러한 bit 수준의 연산 단계를 확인할 수 있는 기능이 있으면 유용합니다.
이 라이브러리에서는 IEEE 표현을 읽기 쉬운 형태로 출력해주는 함수들을 제공합니다.


.. float vs double vs long double 
.. (how many digits are available for each)

.. function:: void gsl_ieee_fprintf_float (FILE * stream, const float * x)
              void gsl_ieee_fprintf_double (FILE * stream, const double * x)

   이 함수들은 주어진 값 :data:`x` 의 IEEE 부동 소수점 숫자 형식을 스트림 :data:`stream`
   에 출력합니다. 포인터를 사용한 이유는 값을 간접적으로 넘겨 :code:`float` 에서 :code:`double`
   의 형 변환을 방지하기 위함입니다. 출력값은 다음의 형태를 가질 수 있습니다.


   :code:`NaN`

      비정상값(Not a number)

   :code:`Inf, -Inf`

      양, 음의 무한대

   :code:`1.fffff...*2^E, -1.fffff...*2^E`

      정규회된 부동 소수 숫자

   :code:`0.fffff...*2^E, -0.fffff...*2^E`

      비정규회된 부동 소수 숫자

   :code:`0, -0`

      양, 음수 0

   결과값은 :code:`2#` 이라는 이진 표현을 표식자를 붙여주면 GNU Emacs Calc에  바로 사용가능합니다.


.. @item [non-standard IEEE float], [non-standard IEEE double]
.. an unrecognized encoding

.. function:: void gsl_ieee_printf_float (const float * x)
              void gsl_ieee_printf_double (const double * x)

   These functions output a formatted version of the IEEE floating-point
   number pointed to by :data:`x` to the stream :code:`stdout`.

The following program demonstrates the use of the functions by printing
the single and double precision representations of the fraction
:math:`1/3`.  For comparison the representation of the value promoted from
single to double precision is also printed.

.. include:: examples/ieee.c
   :code:

The binary representation of :math:`1/3` is :math:`0.01010101...`.  The
output below shows that the IEEE format normalizes this fraction to give
a leading digit of 1::

   f= 1.01010101010101010101011*2^-2
  fd= 1.0101010101010101010101100000000000000000000000000000*2^-2
   d= 1.0101010101010101010101010101010101010101010101010101*2^-2

The output also shows that a single-precision number is promoted to
double-precision by adding zeros in the binary representation.

.. importance of using 1.234L in long double calculations

.. @example
.. int main (void)
.. @{
..   long double x = 1.0, y = 1.0;
  
..   x = x + 0.2;
..   y = y + 0.2L;

..   printf(" d %.20Lf\n",x);
..   printf("ld %.20Lf\n",y);

..   return 1;
.. @}

..  d 1.20000000000000001110
.. ld 1.20000000000000000004
.. @end example

.. index::
   single: IEEE exceptions
   single: precision, IEEE arithmetic
   single: rounding mode
   single: arithmetic exceptions
   single: exceptions, IEEE arithmetic
   single: division by zero, IEEE exceptions
   single: underflow, IEEE exceptions
   single: overflow, IEEE exceptions

Setting up your IEEE environment
================================

The IEEE standard defines several *modes* for controlling the
behavior of floating point operations.  These modes specify the important
properties of computer arithmetic: the direction used for rounding (e.g.
whether numbers should be rounded up, down or to the nearest number),
the rounding precision and how the program should handle arithmetic
exceptions, such as division by zero.

Many of these features can now be controlled via standard functions such
as :func:`fpsetround`, which should be used whenever they are available.
Unfortunately in the past there has been no universal API for
controlling their behavior---each system has had its own low-level way
of accessing them.  To help you write portable programs GSL allows you
to specify modes in a platform-independent way using the environment
variable :macro:`GSL_IEEE_MODE`.  The library then takes care of all the
necessary machine-specific initializations for you when you call the
function :func:`gsl_ieee_env_setup`.

.. macro:: GSL_IEEE_MODE

   Environment variable which specifies IEEE mode.

.. function:: void gsl_ieee_env_setup ()

   This function reads the environment variable :macro:`GSL_IEEE_MODE` and
   attempts to set up the corresponding specified IEEE modes.  The
   environment variable should be a list of keywords, separated by
   commas, like this::

      GSL_IEEE_MODE = "keyword, keyword, ..."

   where :data:`keyword` is one of the following mode-names::

     single-precision
     double-precision
     extended-precision
     round-to-nearest
     round-down
     round-up
     round-to-zero
     mask-all
     mask-invalid
     mask-denormalized
     mask-division-by-zero
     mask-overflow
     mask-underflow
     trap-inexact
     trap-common

   If :macro:`GSL_IEEE_MODE` is empty or undefined then the function returns
   immediately and no attempt is made to change the system's IEEE
   mode.  When the modes from :macro:`GSL_IEEE_MODE` are turned on the
   function prints a short message showing the new settings to remind you
   that the results of the program will be affected.

   If the requested modes are not supported by the platform being used then
   the function calls the error handler and returns an error code of
   :macro:`GSL_EUNSUP`.

   When options are specified using this method, the resulting mode is
   based on a default setting of the highest available precision (double
   precision or extended precision, depending on the platform) in
   round-to-nearest mode, with all exceptions enabled apart from the
   INEXACT exception.  The INEXACT exception is generated
   whenever rounding occurs, so it must generally be disabled in typical
   scientific calculations.  All other floating-point exceptions are
   enabled by default, including underflows and the use of denormalized
   numbers, for safety.  They can be disabled with the individual
   :code:`mask-` settings or together using :code:`mask-all`.

   The following adjusted combination of modes is convenient for many
   purposes::

      GSL_IEEE_MODE="double-precision,"\
                      "mask-underflow,"\
                        "mask-denormalized"

   This choice ignores any errors relating to small numbers (either
   denormalized, or underflowing to zero) but traps overflows, division by
   zero and invalid operations.

   Note that on the x86 series of processors this function sets both the
   original x87 mode and the newer MXCSR mode, which controls SSE
   floating-point operations.  The SSE floating-point units do not have a
   precision-control bit, and always work in double-precision.  The
   single-precision and extended-precision keywords have no effect in
   this case.

To demonstrate the effects of different rounding modes consider the
following program which computes :math:`e`, the base of natural
logarithms, by summing a rapidly-decreasing series,

.. only:: not texinfo

   .. math::

      e &= {1 \over 0!} + {1 \over 1!} + {1 \over 2!} + {1 \over 3!} + {1 \over 4!} + \dots \\
        &= 2.71828182846...

.. only:: texinfo

   ::

      e = 1 + 1/2! + 1/3! + 1/4! + ... 
        = 2.71828182846...

.. include:: examples/ieeeround.c
   :code:

Here are the results of running the program in :code:`round-to-nearest`
mode.  This is the IEEE default so it isn't really necessary to specify
it here::

  $ GSL_IEEE_MODE="round-to-nearest" ./a.out 
  i= 1 sum=1.000000000000000000 error=-1.71828
  i= 2 sum=2.000000000000000000 error=-0.718282
  ....
  i=18 sum=2.718281828459045535 error=4.44089e-16
  i=19 sum=2.718281828459045535 error=4.44089e-16

After nineteen terms the sum converges to within :math:`4 \times 10^{-16}`
of the correct value.  
If we now change the rounding mode to
:code:`round-down` the final result is less accurate::

  $ GSL_IEEE_MODE="round-down" ./a.out 
  i= 1 sum=1.000000000000000000 error=-1.71828
  ....
  i=19 sum=2.718281828459041094 error=-3.9968e-15

The result is about 
:math:`4 \times 10^{-15}`
below the correct value, an order of magnitude worse than the result
obtained in the :code:`round-to-nearest` mode.

If we change to rounding mode to :code:`round-up` then the final result
is higher than the correct value (when we add each term to the sum the
final result is always rounded up, which increases the sum by at least
one tick until the added term underflows to zero).  To avoid this
problem we would need to use a safer converge criterion, such as
:code:`while (fabs(sum - oldsum) > epsilon)`, with a suitably chosen
value of epsilon.

Finally we can see the effect of computing the sum using
single-precision rounding, in the default :code:`round-to-nearest`
mode.  In this case the program thinks it is still using double precision
numbers but the CPU rounds the result of each floating point operation
to single-precision accuracy.  This simulates the effect of writing the
program using single-precision :code:`float` variables instead of
:code:`double` variables.  The iteration stops after about half the number
of iterations and the final result is much less accurate::

  $ GSL_IEEE_MODE="single-precision" ./a.out 
  ....
  i=12 sum=2.718281984329223633 error=1.5587e-07

with an error of 
:math:`O(10^{-7})`,
which corresponds to single
precision accuracy (about 1 part in :math:`10^7`).  Continuing the
iterations further does not decrease the error because all the
subsequent results are rounded to the same value.

References and Further Reading
==============================

The reference for the IEEE standard is,

* ANSI/IEEE Std 754-1985, IEEE Standard for Binary Floating-Point Arithmetic.

A more pedagogical introduction to the standard can be found in the
following paper,

* David Goldberg: What Every Computer Scientist Should Know About
  Floating-Point Arithmetic. *ACM Computing Surveys*, Vol.: 23, No.: 1
  (March 1991), pages 5--48.

* Corrigendum: *ACM Computing Surveys*, Vol.: 23, No.: 3 (September
  1991), page 413. and see also the sections by B. A. Wichmann and Charles
  B. Dunham in Surveyor's Forum: "What Every Computer Scientist Should
  Know About Floating-Point Arithmetic". *ACM Computing Surveys*,
  Vol.: 24, No.: 3 (September 1992), page 319.

A detailed textbook on IEEE arithmetic and its practical use is
available from SIAM Press,

* Michael L. Overton, *Numerical Computing with IEEE Floating Point Arithmetic*,
  SIAM Press, ISBN 0898715717.
