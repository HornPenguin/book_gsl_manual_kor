.. index::
   single: exponential function
   single: exp

이 단원에서 기술하는 함수들은 헤더 파일  ``gsl_sf_exp.h`` 에 정의되어 있습니다.

지수 함수 (Exponential Function)
-------------------------------------

.. function:: double gsl_sf_exp (double x)
              int gsl_sf_exp_e (double x, gsl_sf_result * result)

    지수 함수  :math:`\exp(x)` 의 값을 계산합니다.
    GSL semantics와 오차 검사를 함께 진행합니다.

.. function:: int gsl_sf_exp_e10_e (double x, gsl_sf_result_e10 * result)

    지수 함수  :math:`\exp(x)` 의 값을 계산하는 데, 반환값의 자료형으로 ``gsl_sf_result_e10`` 을 사용해 확장된 크기의 반환값을 계산합니다. 이 함수는  ``double`` 자료형의 범주를 초과한  :math:`\exp(x)` 값을 구할 때, 사용할 수 있습니다.

.. function:: double gsl_sf_exp_mult (double x, double y)
              int gsl_sf_exp_mult_e (double x, double y, gsl_sf_result * result)

    주어진 실수  ``x``  지수 함수 값에 계수  ``y``  곱한 값  :math:`y \exp(x)` 를 계산합니다.

.. function:: int gsl_sf_exp_mult_e10_e (const double x, const double y, gsl_sf_result_e10 * result)

    확장된 범위를 가지는  ``gsl_sf_result_e10`` 자료형을 반환 값에 사용해  :math:`y \exp(x)`  값을 계산합니다.

상대 지수 함수 (Relative Exponential Functions)
-------------------------------------------------

.. function:: double gsl_sf_expm1 (double x)
              int gsl_sf_expm1_e (double x, gsl_sf_result * result)

    :math:`\exp(x)-1` 를 계산합니다. 이 함수에 사용된 알고리즘은 작은 :math:`x` 에서만 정확합니다.

.. function:: double gsl_sf_exprel (double x)
              int gsl_sf_exprel_e (double x, gsl_sf_result * result)

    작은  :math:`x`  값에서 정확한 알고리즘을 이용해  :math:`(\exp(x)-1) /x` 값을 계산합니다. 작은 :math:`x`  값에 대해, 알고리즘은 다음과 같은 확장을 이용합니다.

    .. math::
    
        (\exp(x)-1) /x = 1 + x/2 + x^2/(2 \cdot 3) + x^3/(2 \cdot 3 \cdot 4) + \dots

.. function:: double gsl_sf_exprel_2 (double x)
              int gsl_sf_exprel_2_e (double x, gsl_sf_result * result)

    작은 :math:`x` 값에서 정확한 알고리즘을 이용해  :math:`2(\exp(x)-1 -x) /x^2` 값을 계산합니다. 
    작은 :math:`x` 값에 대해, 알고리즘은 다음과 같은 확장을 이용합니다.

    .. math::
        
        2(\exp(x)-1 -x) /x^2 = 1 + x/3 + x^2/(3 \cdot 4) + x^3/(3 \cdot 4 \cdot 5) + \dots


.. function:: double gsl_sf_exprel_n (int n, double x)
              int gsl_sf_exprel_n_e (int n, double x, gsl_sf_result * result)

    :math:`N-` 상대 지수 함수 값을 계산합니다. 이 함수는  ``gsl_sf_exprel()`` 와 ``gsl_sf_exprel_2()`` 의  ``n`` 차 일반화 함수입니다. 
    다음과 같이 주어집니다.

    .. math::

        \begin{flalign}
        \text{exprel}\_N (x) &= N!/x^N (\exp(x) - \sum\_{k=0}^{N-1} x^k/k!) \\\\ 
        &= 1+x/(N+1) + x^2/((N+1)(N+2)) + \dots \\\\
        &=  {}\_1F\_1(1,1+N,x)
        \end{flalign}

오차 평가가 있는 지수 함수 (Exponentiation With Error Estimate)
------------------------------------------------------------------

.. function:: int gsl_sf_exp_err_e (double x, double dx, gsl_sf_result * result)

    주어진 ``x`` 의 지수함수 값을 절대 오차 ``dx``  함께 반환합니다.

.. function:: int gsl_sf_exp_err_e10_e (double x, double dx, gsl_sf_result_e10 * result)

    주어진 ``x`` 의 지수함수 값을 절대 오차 ``dx``  함께 반환합니다. 
    이때, 반환 값의 자료형을  ``gsl_sf_result_e10`` 을 사용해 확장된 범위의 결과를 계산할 수 있습니다.

.. function:: int gsl_sf_exp_mult_err_e (double x, double dx, double y, double dy, gsl_sf_result * result)

    ``x`` 와 ``y``  대해,  :math:`y \exp(x)` 값을 절대 오차 ``dx``  ``dy``  함께 계산합니다.

.. function:: int gsl_sf_exp_mult_err_e10_e (double x, double dx, double y, double dy, gsl_sf_result_e10 * result)

    ``x`` 와 ``y``  대해,  :math:`y \exp(x)` 값을 절대 오차 ``dx``  ``dy``  함께 계산합니다. 
    이때, 반환 값의 자료형을  ``gsl_sf_result_e10`` 을 사용해 확장된 범위의 결과를 계산할 수 있습니다.
