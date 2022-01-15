
.. index:: IEEE floating point 

.. _chap_ieee:

**************************
IEEE  부동 소수점 대수
**************************

.. note::

    번역중

이 단원에서는 부동 소수 표현을 검증하고, 
제어할 수 있는 함수들에 대해 기술합니다. 
함수들은 헤더 파일 
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
부호( :math:`s` ), 지수( :math:`E` ), 그리고 소수점( :math:`f` )입니다. :math:`(s,E,f)` 표현의
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

IEEE의 이진 부동 소수 대수 표준은 다음과 같이 정의됩니다.

.. index::
   single: zero, IEEE format
   single: infinity, IEEE format

:math:`p` 비트의 정밀도에서 점진적 언더플로우 값으로 :math:`2^{E_{min} - p}` 를 
반환합니다.


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

   :data:`x` 가 가르키는 숫자를 형식화 된 IEEE 부동소수점 표현으로  
   :code:`stdout` 에 출력합니다.

다음 프로그램은 이 함수들을 사용해 :math:`1/3` 를 단, 배정밀도 표현으로
출력하는 방법을 보여줍니다. 비교를 위해 일반적인 단, 배 정밀도 값도 같이 출력됩니다. 
The following program demonstrates the use of the functions by printing
the single and double precision representations of the fraction
:math:`1/3`.  
For comparison the representation of the value promoted from
single to double precision is also printed.

.. include:: examples/ieee.c
   :code:

:math:`1/3` 의 이진 표현은 :math:`0.01010101...` 입니다. 아래의 결과는
IEEE 형식의 정규화 표현에서 이 분수 값의 앞 자릿수는 1이라는 사실을 보여줍니다.


::

   f= 1.01010101010101010101011*2^-2
  fd= 1.0101010101010101010101100000000000000000000000000000*2^-2
   d= 1.0101010101010101010101010101010101010101010101010101*2^-2

이 결과는 단 정밀도 숫자가 배 정밀도로 변환될 때, 이진 표현의 나머지 자릿수에
0을 넣어서 변환함을 보여줍니다.

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

IEEE 환경 설정
================================

IEEE 표준은 부동 소수점 연산을 제어하기 위해 몇가지 특정 *환경 상태* 들을 정의합니다.
이 환경들은 컴퓨터의 연산의 중요한 성질들을 특정 짓습니다.
절단의 방향(해당 숫자를 인접한 숫자로 올릴지, 내릴지 결정합니다.), 반올림 정밀도, 그리고 
연산의 예외(예: 0으로 나누기)를 어떻게 처리할 지 등이 있습니다.

이러한 성질들의 상당수는 :func:`fpsetround` 와 같은 표준 함수들로 제어됩니다.
물론, 이러한 표준 함수들이 사용 가능할 때에 한정된 상황입니다.
불행히도, 옛날에는 이러한 행동들을 제어할만한 표준 API가 없었습니다. 각각의
시스템들은 이러한 행동들을 저수준에서 직접 접근해 사용했습니다.
프로그램의 이식성 구현을 돕기 위해 GSL에서는 플랫폼에 독립적으로 이러한 환경을
제어할 수 있는 환경 변수 :macro:`GSL_IEEE_MODE` 을 제공합니다.
:func:`gsl_ieee_env_setup` 함수를 호출하면 라이브러리는 기계에 설정되어 있는 필요한 모든 사항들을
초기화합니다.


.. macro:: GSL_IEEE_MODE

   IEEE 환경 상태를 특정짓는 환경 변수입니다.

.. function:: void gsl_ieee_env_setup ()

   환경 변수 :macro:`GSL_IEEE_MODE` 를 읽고 대응 되는 특정 IEEE 환경으로 시스템을
   설정합니다. 환경 변수는 다음의 목록에 있는 값들로 구성되어야 하며, 쉼표로 구분됩니다.
   다음과 같이 작성할 수 있습니다.
   
   ::

      GSL_IEEE_MODE = "keyword, keyword, ..."

   :data:`keyword` 는 다음의 상태 이름들로 작성해야 합니다.
   
   ::

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

   :macro:`GSL_IEEE_MODE` 가 비어있거나 정의되지 않으면, 이 함수는 즉시
   종료되며 시스템의 IEEE 환경을 바꾸지 않습니다. :macro:`GSL_IEEE_MODE` 에
   정의된 상태들이 함수에 의해 설정되면 이를 알리기 위해 짧은 알림 메세지가 출력되고
   해당 IEEE 환경이 적용됩니다.

   요구한 환경들을 플랫폼에서 지원하지 않는다면 이 함수는 오류 관리자를 부르고
   :macro:`GSL_EUNSUP` 오류 값을 반환합니다.

   이 방법을 통해 IEEE 환경을 설정할 경우, 설정된 환경 설정들은 기본적으로 
   :code:`round-to-nearest` 환경에서 사용가능한 한 가장 높은 정밀도를 가지는 
   상태로 특정됩니다. (이 상태는 배정밀도거나 확장된 정밀도를 가지는 
   등 플랫폼에 따라 다양합니다.) 또한, INEXACT 예외를 제외한 모든 예외가 
   활성화 됩니다. INEXACT 예외는 절단이 발생하는 상황에서 발생하기 때문에
   일반적인 과학 계산상황에서 비활성화 됩니다. 이들은 독립적으로 :code:`mask-` 가 붙은
   환경 설정으로 비활성화 하거나 :code:`mask-all` 로 모두 비활성화 시킬 수 있습니다.
   

   다음의 환경 변수 설정이 많은 상황에서 공통적으로 쓰입니다.
   
   ::

      GSL_IEEE_MODE="double-precision,"\
                      "mask-underflow,"\
                        "mask-denormalized"

   이 설정은 작은 숫자들에 관련된 오류들(비정규화나 0으로 언더플로우)을 무시합니다. 
   하지만, 오버플로우나 0으로 나누기 그리고 정의되지 않은 연산들을 잡아낼 수 있습니다.

   .. note::
      
      x86 계열의 프로세스들에서 이 함수는 본래의 x87환경과 새로운 MXCSR 환경을 모두 설정합니다.
      이들은 SSE 부동 소수 연산을 제어합니다. SSE 부동 소수 유닛는 정밀도 제어 비트를 가지고 있지않고
      항상 배 정밀도로 연산합니다. 단 정밀도와 확장된 정밀도 설정은 이러한 경우 어떠한 영향도 미치지 않습니다.

각기 다른 절단 환경 설정이 계산에 미치는 영향을 보여주기 위해
다음 프로그램은 :math:`e` 를 계산하는 방법을 자연 로그와 급격히 감소하는 급수를 이용해
보여줍니다.


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

다음 결과는 :code:`round-to-nearest` 설정에서 나온 결과입니다. 
이는 IEEE 대수의 기본 설정이기 때문에 달리 설명할 사항은 없습니다.

::

  $ GSL_IEEE_MODE="round-to-nearest" ./a.out 
  i= 1 sum=1.000000000000000000 error=-1.71828
  i= 2 sum=2.000000000000000000 error=-0.718282
  ....
  i=18 sum=2.718281828459045535 error=4.44089e-16
  i=19 sum=2.718281828459045535 error=4.44089e-16

19번째 항 이후로 이 급수는 참 값에 :math:`4 \times 10^{-16}` 내의 오차로 수렴합니다.

이제 절단 설정을 :code:`round-down` 로 바꾸어 절단을 내림으로 정의합시다. 
이 경우 최종 결과값이 이전 계산보다 덜 정확하게 나옵니다.

  $ GSL_IEEE_MODE="round-down" ./a.out 
  i= 1 sum=1.000000000000000000 error=-1.71828
  ....
  i=19 sum=2.718281828459041094 error=-3.9968e-15

결과 값이 참 값에 :math:`4 \times 10^{-15}` 내의 오차로 수렴합니다. 
:code:`round-to-nearest` 설정의 결과보다 크기 측면에서 더 안좋은 결과가 나왔습니다.

절단 설정을 :code:`round-up` 로 바꾸어 올림으로 정의할 경우 최종 결과값은
참 값보다 크게 나옵니다. (각 항을 더할 때마다 계산 결과 값이 항상 올려집니다. 이는 추가된 항이 0으로 언더플로우 되기 전까지
적어도 합을 최소 단위의 1 이상 증가시킵니다.)
이를 피하기 위해 적절하게 정의된 :code:`epsilon` 값을 이용해
:code:`while (fabs(sum - oldsum) > epsilon)` 형태의 수렴 조건을 만들어야 합니다.

마지막으로, 단 정밀도 절단을 이용한 합 계산을 봅시다. 기본 설정은  
:code:`round-to-nearest` 환경입니다. 이 경우 프로그램은 여전이 배 정밀도로 숫자를
계산하고 있다고 간주하지만 CPU에서 각각의 부동 소수 연산을 단 정밀도의 정밀도로 절단합니다.
이는 프로그램을 :code:`double` 변수들로 작성하는 대신 :code:`float` 으로 작성했을 때를 
시뮬레이션할 수 있습니다. 반복문이 절반의 횟수에서 종료되고 최종 계산 값은
더 낮은 정확도를 가집니다.

::

  $ GSL_IEEE_MODE="single-precision" ./a.out 
  ....
  i=12 sum=2.718281984329223633 error=1.5587e-07

오차는 :math:`O(10^{-7})` 로 단 정밀도의 정확도( :math:`10^7` 크기의 숫자 )에 대응 되는 값입니다. 
반복문을 계속 수행하는 행위는 의미가 없습니다. 이후의 모든 합이
동일한 값으로 절단되기 때문입니다.



참고 문헌과 추가 자료
==============================

IEEE 표준에 관한 참고 문헌은 다음을 볼 수 있습니다.

* ANSI/IEEE Std 754-1985, IEEE Standard for Binary Floating-Point Arithmetic.

다음 논문들에서 표준에 관해 더 많은 교육 자료를 볼 수 있습니다.

* David Goldberg: What Every Computer Scientist Should Know About
  Floating-Point Arithmetic. *ACM Computing Surveys*, Vol.: 23, No.: 1
  (March 1991), pages 5--48.

* Corrigendum: *ACM Computing Surveys*, Vol.: 23, No.: 3 (September
  1991), page 413. and see also the sections by B. A. Wichmann and Charles
  B. Dunham in Surveyor's Forum: "What Every Computer Scientist Should
  Know About Floating-Point Arithmetic". *ACM Computing Surveys*,
  Vol.: 24, No.: 3 (September 1992), page 319.

SIAM 출판에서 IEEE 대수에 관한 내용과 실용적 사용의 예시 교재를 찾을 수 있습니다.

* Michael L. Overton, *Numerical Computing with IEEE Floating Point Arithmetic*,
  SIAM Press, ISBN 0898715717.
