.. index:: 베셀 함수

이 단원은 
원통형 베셀 함수 :math:`J_ (x), Y_(x)`, 
수정 베셀 함수 :math:`I_(x), K_(x)`, 
구면 베셀 함수 :math:`j_l(x), y_l(x)` 그리고 
수정 구면 베셀 함수 :math:`i_(x), k_l(x)`를 계산하는 함수들을 서술합니다. 
더 자세한 정보는 Abramowitz & Stegun Chapter 9, 10 단원을 참조할 수 있습니다. 
이 베셀함수들은 헤더 파일 ``gsl_sf_bessel.h`` 에 정의되어 있습니다.


1종 베셀 함수(Regular Bessel function, Bessel function of the first kind)
---------------------------------------------------------------------------

Regular Cylindrical Bessel Functions

.. function:: double gsl_sf_bessel_J0 (double x)
              int gsl_sf_bessel_J0_e (double x, gsl_sf_result * result)

    :math:`0` 차수의 1종 베셀 함수 :math:`J_0(x)`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_J1 (double x)
              int gsl_sf_bessel_J1_e (double x, gsl_sf_result * result)

    :math:`1` 차수의 1종 베셀 함수 :math:`J_1(x)`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_Jn (int n, double x)
              int gsl_sf_bessel_Jn_e (int n, double x, gsl_sf_result * result)

    주어진 ``n`` 차수의 1종 베셀 함수 :math:`J_n(x)`의 값을 계산합니다.

.. function:: int gsl_sf_bessel_Jn_array (int nmin, int nmax, double x, double result_array[])

    ``nmin`` 에서 ``nmax`` 까지, 1종 베셀 함수 :math:`J_n(x)`의 값을 계산합니다. 
    계산 결과값은 ``result_array`` 배열에 저장됩니다. 재귀식을 이용해 계산 효율을 높여, 
    실제 값과는 조금 다를 수 있습니다.


2종 베셀 함수/ 노이먼 함수(Irregular Bessel function, Bessel function of the second kind, Neumann function)
---------------------------------------------------------------------------------------------------------------------------------

Irregular Cylindrical Bessel Functions

.. function:: double gsl_sf_bessel_Y0 (double x)
              int gsl_sf_bessel_Y0_e (double x, gsl_sf_result * result)

    :math:`x>0`에 대해, :math:`0` 차수의 2종 베셀 함수 :math:`Y_0(x)` 값을 계산합니다. 

.. function:: double gsl_sf_bessel_Y1 (double x)
              int gsl_sf_bessel_Y1_e (double x, gsl_sf_result * result)

    :math:`x>0`에 대해, :math:`1` 차수의 2종 베셀 함수 :math:`Y_1(x)` 값을 계산합니다. 

.. function:: double gsl_sf_bessel_Yn (int n, double x)
              int gsl_sf_bessel_Yn_e (int n, double x, gsl_sf_result * result)

    :math:`x>0`에 대해, 주어진 ``n`` 차수의 2종 베셀 함수 :math:`Y_1(x)` 값을 계산합니다. 

.. function:: int gsl_sf_bessel_Yn_array (int nmin, int nmax, double x, double result_array[])

    ``nmin`` 에서 ``nmax`` 까지, 2종 베셀 함수 :math:`Y_n(x)`의 값을 계산합니다. 
    계산 결과값은 ``result_array`` 배열에 저장됩니다. 이 함수의 정의역은 :math:`x>0`입니다. 
    재귀식을 이용해 계산 효율을 높여, 실제 값과는 조금 다를 수 있습니다.

1종 변형 베셀 함수(Regular Modified Cylindrical Bessel Functions)
---------------------------------------------------------------------------

.. function:: double gsl_sf_bessel_I0 (double x)
              int gsl_sf_bessel_I0_e (double x, gsl_sf_result * result)

    :math:`0` 차수의 1종 변형 베셀 함수 :math:`I_0(x)`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_I1 (double x)
              int gsl_sf_bessel_I1_e (double x, gsl_sf_result * result)

    :math:`1` 차수의 1종 변형 베셀 함수 :math:`1_0(x)`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_In (int n, double x)
              int gsl_sf_bessel_In_e (int n, double x, gsl_sf_result * result)

    주어진 ``n`` 차수의 1종 변형 베셀 함수 :math:`I_n(x)`의 값을 계산합니다.

.. function:: int gsl_sf_bessel_In_array (int nmin, int nmax, double x, double result_array[])

    ``nmin`` 에서 ``nmax`` 까지, 1종 변형 베셀 함수 :math:`I_n(x)`의 값을 계산합니다. 
    계산 결과값은 ``result_array`` 배열에 저장됩니다. ``nmin`` 는 반드시 양수이거나 :math:`0`이어야 합니다. 
    재귀식을 이용해 계산 효율을 높여, 실제 값과는 조금 다를 수 있습니다.

.. function:: double gsl_sf_bessel_I0_scaled (double x)
              int gsl_sf_bessel_I0_scaled_e (double x, gsl_sf_result * result)

    조정 계수가 곱해진 :math:`0` 차수의 1종 변형 베셀 함수 :math:`\text{exp}(-|x|) I_0(x)`를 계산합니다.

.. function:: double gsl_sf_bessel_I1_scaled (double x)
              int gsl_sf_bessel_I1_scaled_e (double x, gsl_sf_result * result)

    조정 계수가 곱해진 :math:`1` 차수의 1종 변형 베셀 함수 :math:`\text{exp}(-|x|) I_1(x)`를 계산합니다.

.. function:: double gsl_sf_bessel_In_scaled (int n, double x)
              int gsl_sf_bessel_In_scaled_e (int n, double x, gsl_sf_result * result)

    조정 계수가 곱해진, ``n`` 차수의 1종 변형 베셀 함수 :math:`\text{exp}(-|x|) I_n(x)`를 계산합니다.

.. function:: int gsl_sf_bessel_In_scaled_array (int nmin, int nmax, double x, double result_array[])

    ``nmin`` 에서 ``nmax`` 까지, 조정 계수가 곱해진, 1종 변형 베셀 함수 :math:`\text{exp}(-|x|)I_n(x)`의 값을 계산합니다. 계산 결과값은 ``result_array`` 배열에 저장됩니다. ``nmin``  반드시 양수이거나 :math:`0`이어야 합니다. 재귀식을 이용해 계산 효율을 높여, 실제 값과는 조금 다를 수 있습니다.

2종 변형 베셀 함수(Irregular Modified Cylindrical Bessel Functions)
---------------------------------------------------------------------------

.. function:: double gsl_sf_bessel_K0 (double x)
              int gsl_sf_bessel_K0_e (double x, gsl_sf_result * result)

    :math:`x>0`에 대해, :math:`0` 차수의 2종 변형 베셀 함수 :math:`K_0(x)` 값을 계산합니다. 

.. function:: double gsl_sf_bessel_K1 (double x)
              int gsl_sf_bessel_K1_e (double x, gsl_sf_result * result)

:math:`x>0`에 대해, :math:`1` 차수의 2종 변형 베셀 함수 :math:`K_1(x)` 값을 계산합니다. 

.. function:: double gsl_sf_bessel_Kn (int n, double x)
              int gsl_sf_bessel_Kn_e (int n, double x, gsl_sf_result * result)

:math:`x>0`에 대해, ``n`` 차수의 2종 변형 베셀 함수 :math:`K_n(x)` 값을 계산합니다. 

.. function:: int gsl_sf_bessel_Kn_array (int nmin, int nmax, double x, double result_array[])

 ``nmin`` 에서 ``nmax`` 까지, 2종 변형 베셀 함수 :math:`K_n(x)`의 값을 계산합니다. 계산 결과값은 ``result_array`` 배열에 저장됩니다. ``nmin``  반드시 양수이거나 :math:`0`이어야 합니다. 함수의 정의역은 :math:`x>0`입니다. 재귀식을 이용해 계산 효율을 높여, 실제 값과는 조금 다를 수 있습니다.

.. function:: double gsl_sf_bessel_K0_scaled (double x)
              int gsl_sf_bessel_K0_scaled_e (double x, gsl_sf_result * result)

:math:`x>0`에 대해, 조정 계수가 곱해진 :math:`0` 차수의 2종 변형 베셀 함수 :math:`\text{exp}(x) K_0(x)`를 계산합니다.


.. function:: double gsl_sf_bessel_K1_scaled (double x) 
              int gsl_sf_bessel_K1_scaled_e (double x, gsl_sf_result * result)

:math:`x>0`에 대해, 조정 계수가 곱해진 :math:`1` 차수의 2종 변형 베셀 함수 :math:`\text{exp}(x) K_1(x)`를 계산합니다.


.. function:: double gsl_sf_bessel_Kn_scaled (int n, double x)
              int gsl_sf_bessel_Kn_scaled_e (int n, double x, gsl_sf_result * result)


:math:`x>0`에 대해, 조정 계수가 곱해진 ``n`` 차수의 2종 변형 베셀 함수 :math:`\text{exp}(x) K_n(x)`를 계산합니다.

.. function:: int gsl_sf_bessel_Kn_scaled_array (int nmin, int nmax, double x, double result_array[])

    ``nmin`` 에서 ``nmax`` 까지, 조정 계수가 곱해진 2종 변형 베셀 함수 :math:`\text{exp}(x) K_n(x)`의 값을 계산합니다. 계산 결과값은 ``result_array`` 배열에 저장됩니다. ``nmin``  반드시 양수이거나 :math:`0`이어야 합니다. 함수의 정의역은 :math:`x>0`입니다. 재귀식을 이용해 계산 효율을 높여, 실제 값과는 조금 다를 수 있습니다.

1종 구면 베셀 함수(Regular Spherical Bessel Functions)
---------------------------------------------------------------------------

.. function:: double gsl_sf_bessel_j0 (double x)
              int gsl_sf_bessel_j0_e (double x, gsl_sf_result * result)

    :math:`0` 차수의 1종 구면 베셀 함수 :math:`j_0 (x) = \sin (x) /x`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_j1 (double x)
              int gsl_sf_bessel_j1_e (double x, gsl_sf_result * result)

    :math:`1` 차수의 1종 구면 베셀 함수 :math:`j_1 (x) = (\sin (x) /x - \cos(x)) /x`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_j2 (double x)
              int gsl_sf_bessel_j2_e (double x, gsl_sf_result * result)


    :math:`2` 차수의 1종 구면 베셀 함수 :math:`j_2 (x) = ((3/x^2 -1)\sin(x) -3 \cos(x)/x) /x`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_jl (int l, double x)
              int gsl_sf_bessel_jl_e (int l, double x, gsl_sf_result * result)

    ``l`` 차수의 1종 구면 베셀 함수 :math:`j_l (x)`의 값을 계산합니다. :math:`x,l`은 :math:`l \geq 0, x \geq 0`이어야 합니다. 

.. function:: int gsl_sf_bessel_jl_array (int lmax, double x, double result_array[])

    :math:`lmax \geq 0, x \geq 0`에 대해, 1종 구면 베셀 함수 :math:`j_l(x)`의 값을 :math:`l=0`에서 :math:`l=lmax`까지 계산합니다. 계산 결과값은 ``result_array`` 배열에 저장됩니다. 재귀식을 이용해 계산 효율을 높여, 실제 값과는 조금 다를 수 있습니다.

.. function:: int gsl_sf_bessel_jl_steed_array (int lmax, double x, double * result_array)

    Steed 방법을 이용해 1종 구면 베셀 함수 :math:`j_l(x)`의 값을 :math:`l=0`에서 :math:`l=lmax`까지 계산합니다. :math:`lmax, x`는 :math:`lmax \geq 0, x \geq 0`이어야 합니다. 계산 결과값은 ``result_array`` 배열에 저장됩니다. Steed/Barnett 알고리즘은 Comp. Phys. Comm. 21, 297(1981)에 기술되어 있습니다. Steed 방법은 다른 함수의 재귀적 방법보다 더 안정적이지만, 그대신 더 느립니다.

2종 구면 베셀 함수(Irregular Spherical Bessel Functions)
---------------------------------------------------------------------------

.. function:: double gsl_sf_bessel_y0 (double x)
              int gsl_sf_bessel_y0_e (double x, gsl_sf_result * result)

    :math:`0` 차수의 2종 구면 베셀 함수 :math:`y_0 (x) = -\cos (x) /x`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_y1 (double x)
              int gsl_sf_bessel_y1_e (double x, gsl_sf_result * result)

    :math:`1` 차수의 2종 구면 베셀 함수 :math:`y_1 (x) = -(\cos (x) /x + \sin (x))/x`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_y2 (double x)
              int gsl_sf_bessel_y2_e (double x, gsl_sf_result * result)

    :math:`2` 차수의 2종 구면 베셀 함수 :math:`y_2 (x) = (-3/x^3 + 1/x)\cos(x) - (3/x^2)\sin(x)`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_yl (int l, double x)
              int gsl_sf_bessel_yl_e (int l, double x, gsl_sf_result * result)

    :math:`l \geq 0`에 대해, ``l`` 차수의 2종 구면 베셀 함수 :math:`y_l (x)`의 값을 계산합니다.

.. function:: int gsl_sf_bessel_yl_array (int lmax, double x, double result_array[])

    :math:`lmax \geq 0`에 대해, 2종 구면 베셀 함수 :math:`y_l(x)`의 값을 :math:`l=0`에서 :math:`l=lmax`까지 계산합니다. 계산 결과값은 ``result_array`` 배열에 저장됩니다. 재귀식을 이용해 계산 효율을 높여, 실제 값과는 조금 다를 수 있습니다.

1종 변형 구면 베셀 함수(Regular Modified Spherical Bessel Functions)
---------------------------------------------------------------------------

1종 변형 구면 베셀함수 :math:`i_l(x)`는 분수 차수의 1종 수정 베셀함수와 다음과 같은 관계를 가집니다.

.. math:: 

    i_l(x) = \sqrt{\pi/(2x)}I_{l + 1/2}(x)

.. function:: double gsl_sf_bessel_i0_scaled (double x)
              int gsl_sf_bessel_i0_scaled_e (double x, gsl_sf_result * result)

    조정 계수가 곱해진, :math:`0` 차수의 1종 변형 구면 베셀 함수 :math:`\text{exp}(-|x|) i_0 (x)`를 계산합니다.

.. function:: double gsl_sf_bessel_i1_scaled (double x)
              int gsl_sf_bessel_i1_scaled_e (double x, gsl_sf_result * result)

    조정 계수가 곱해진, :math:`1` 차수의 1종 변형 구면 베셀 함수 :math:`\text{exp}(-|x|) i_1 (x)`를 계산합니다.

.. function:: double gsl_sf_bessel_i2_scaled (double x)
              int gsl_sf_bessel_i2_scaled_e (double x, gsl_sf_result * result)

    조정 계수가 곱해진, :math:`2` 차수의 1종 변형 구면 베셀 함수 :math:`\text{exp}(-|x|) i_2 (x)`를 계산합니다.

.. function:: double gsl_sf_bessel_il_scaled (int l, double x)
              int gsl_sf_bessel_il_scaled_e (int l, double x, gsl_sf_result * result)


    조정 계수가 곱해진, ``l`` 차수의 1종 변형 구면 베셀 함수 :math:`\text{exp}(-|x|) i_2 (x)`를 계산합니다.

.. function:: int gsl_sf_bessel_il_scaled_array (int lmax, double x, double result_array[])

    :math:`lmax \geq 0, x \geq 0`에 대해, 조정 계수가 곱해진 1종 변형 구면 베셀 함수 :math:`\text{exp}(-|x|) i_l(x)`의 값을 :math:`l=0`에서 :math:`l=lmax`까지 계산합니다. 계산 결과값은 ``result_array`` 배열에 저장됩니다. 재귀식을 이용해 계산 효율을 높여, 실제 값과는 조금 다를 수 있습니다.

2종 변형 구면 베셀 함수(Irregular Modified Spherical Bessel Functions)
-------------------------

2종 변형 구면 베셀함수 :math:`k_l(x)`는 분수 차수 2종 구면 베셀 함수와 다음과 같은 관계를 가집니다.

.. math::
    
    k_l(x) = \sqrt{\pi / (2x) K_{l+1/2}(x)}

.. function:: double gsl_sf_bessel_k0_scaled (double x)
              int gsl_sf_bessel_k0_scaled_e (double x, gsl_sf_result * result)

    :math:`x>0`에 대해, 조정 계수가 곱해진 :math:`0` 차수의 2종 변형 구면 베셀 함수 :math:`\text{exp}(x)k_0(x)`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_k1_scaled (double x)
              int gsl_sf_bessel_k1_scaled_e (double x, gsl_sf_result * result)

    :math:`x>0`에 대해, 조정 계수가 곱해진 :math:`1` 차수의 2종 변형 구면 베셀 함수 :math:`\text{exp}(x)k_1(x)`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_k2_scaled (double x)
              int gsl_sf_bessel_k2_scaled_e (double x, gsl_sf_result * result)

    :math:`x>0`에 대해, 조정 계수가 곱해진 :math:`2` 차수의 2종 변형 구면 베셀 함수 :math:`\text{exp}(x)k_2(x)`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_kl_scaled (int l, double x)
              int gsl_sf_bessel_kl_scaled_e (int l, double x, gsl_sf_result * result)

    :math:`x>0`에 대해, 조정 계수가 곱해진 ``l`` 차수의 2종 변형 구면 베셀 함수 :math:`\text{exp}(x)k_l(x)`의 값을 계산합니다.

.. function:: int gsl_sf_bessel_kl_scaled_array (int lmax, double x, double result_array[])

    :math:`lmax \geq 0, x \geq 0`에 대해, 조정 계수가 곱해진 1종 변형 구면 베셀 함수 :math:`\text{exp}(x) k_l(x)`의 값을 :math:`l=0`에서 :math:`l=lmax`까지 계산합니다. 계산 결과값은 ``result_array`` 배열에 저장됩니다. 재귀식을 이용해 계산 효율을 높여, 실제 값과는 조금 다를 수 있습니다.

1종 베셀 함수-분수 차수(Regular Bessel Function—Fractional Order)
------------------------------------------------------------------


.. function:: double gsl_sf_bessel_Jnu (double nu, double x)
              int gsl_sf_bessel_Jnu_e (double nu, double x, gsl_sf_result * result)

    분수 차수 :math:`\nu`에 대해, 1종 베셀함수 :math:`J_\nu (x)`의 값을 계산합니다.

.. function:: int gsl_sf_bessel_sequence_Jnu_e (double nu, gsl_mode_t mode, size_t size, double v[])

    분수 차수 :math:`\nu`의 1종 배셀함수 :math:`J_\nu (x)`의 값을 주어진 :math:`x` 값 배열에 대해 계산합니다. ``size`` 길이의 배열 ``v`` :math:`x` 값들을 담고있습니다. 함수는 이 배열이 양수가 순차적으로 배열되어 있다 가정합니다.  ``v`` 배열을 수정해 :math:`J_\nu (x_i)` 값을 덮어 씌웁니다.

2종 베셀 함수-분수 차수(Irregular Bessel Functions—Fractional Order)
---------------------------------------------------------------------


.. function:: double gsl_sf_bessel_Ynu (double nu, double x)
              int gsl_sf_bessel_Ynu_e (double nu, double x, gsl_sf_result * result)

    분수 차수 :math:`\nu`에 대해, 2종 베셀함수 :math:`Y_\nu (x)`의 값을 계산합니다.
  
1종 변형 베셀 함수-분수 차수(Regular Modified Bessel Functions—Fractional Order)
----------------------------------------------------------------------------------


.. function:: double gsl_sf_bessel_Inu (double nu, double x)
              int gsl_sf_bessel_Inu_e (double nu, double x, gsl_sf_result * result)

    :math:`x>0, \nu>0`에 대해, 분수 차수 :math:`\nu`의 1종 변형 베셀 함수 :math:`I_\nu(x)`를 계산합니다.

.. function:: double gsl_sf_bessel_Inu_scaled (double nu, double x)
              int gsl_sf_bessel_Inu_scaled_e (double nu, double x, gsl_sf_result * result)

 
    :math:`x>0, \nu>0`에 대해, 조정 계수가 곱해진 분수 차수 :math:`\nu`의 2종 변형 베셀 함수 :math:`\text{exp}(-|x|)I_\nu (x)`의 값을 계산합니다.

2종 변형 베셀 함수-분수 차수(Irregular Modified Bessel Functions—Fractional Order)
-------------------------

.. function:: double gsl_sf_bessel_Knu (double nu, double x)
              int gsl_sf_bessel_Knu_e (double nu, double x, gsl_sf_result * result)


    :math:`x>0, \nu>0`에 대해, 분수 차수 :math:`\nu`의 2종 변형 베셀 함수 :math:`K_\nu (x)`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_lnKnu (double nu, double x)
              int gsl_sf_bessel_lnKnu_e (double nu, double x, gsl_sf_result * result)


    :math:`x>0, \nu>0`에 대해, 로그가 씌워진, 분수 차수 :math:`\nu`의 2종 변형 베셀 함수 :math:`\ln(K_\nu (x))`의 값을 계산합니다.

.. function:: double gsl_sf_bessel_Knu_scaled (double nu, double x)
              int gsl_sf_bessel_Knu_scaled_e (double nu, double x, gsl_sf_result * result)


    :math:`x>0, \nu>0`에 대해, 조정 계수가 곱해진 분수 차수 :math:`\nu`의 2종 변형 베셀 함수 :math:`\text{exp}(+|x|)K_\nu (x)`의 값을 계산합니다.

1종 베셀 함수의 근(Zeros of Regular Bessel Functions)
-------------------------

.. function:: double gsl_sf_bessel_zero_J0 (unsigned int s)
              int gsl_sf_bessel_zero_J0_e (unsigned int s, gsl_sf_result * result)

    :math:`0` 차수의 베셀 함수 :math:`J_0(x)`의 ``s`` 번째, 양수 근의 위치를 찾습니다.

.. function:: double gsl_sf_bessel_zero_J1 (unsigned int s)
              int gsl_sf_bessel_zero_J1_e (unsigned int s, gsl_sf_result * result)

    :math:`1` 차수의 베셀 함수 :math:`J_1(x)`의 ``s`` 번째, 양수 근의 위치를 찾습니다.

.. function:: double gsl_sf_bessel_zero_Jnu (double nu, unsigned int s)
              int gsl_sf_bessel_zero_Jnu_e (double nu, unsigned int s, gsl_sf_result * result)


    베셀함수 :math:`J_\nu (x)`에 대해, ``s`` 번째, 양수 근의 위치를 찾습니다. 
    현재 구현체는 ``nu`` 가 음수일 때를 지원하지 않습니다.
