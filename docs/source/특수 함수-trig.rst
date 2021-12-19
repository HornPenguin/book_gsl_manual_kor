
본 라이브러리는 여러 플랫폼에서 일관적인 코드 작성과 신뢰할 수 있는 오류 측정을 위해 자체적인 삼각 함수를 포함하고 있습니다. 
    헤더파일 :code:`gsl_sf_trig.h` 에 정의되어 있습니다.

삼각 함수 (Circular Trigonometric Functions)
-----------------------------------------------------------

.. function:: double gsl_sf_sin (double x)
              int gsl_sf_sin_e (double x, gsl_sf_result * result)

    sine 함수 :math:`\sin(x)`  를 계산합니다.

.. function:: double gsl_sf_cos (double x)
              int gsl_sf_cos_e (double x, gsl_sf_result * result)

    cosine 함수 :math:`\cos(x)`  를 계산합니다.

.. function:: double gsl_sf_hypot (double x, double y)
              int gsl_sf_hypot_e (double x, double y, gsl_sf_result * result)

    오버 플로우와 언더 플로우 없는 :math:`\sqrt{x^2+y^2}` 값을 계산합니다.

.. function:: double gsl_sf_sinc (double x)
              int gsl_sf_sinc_e (double x, gsl_sf_result * result)

    :math:`x` 에 대해, :math:`\text{sinc}(x) = \sin(\pi x)/(\pi x)` 값을 계산합니다.

복소 삼각 함수 (Trigonometric Functions for Complex Arguments)
-------------------------------------------------------------------------

.. function:: int gsl_sf_complex_sin_e (double zr, double zi, gsl_sf_result * szr, gsl_sf_result * szi)

    복소 sine 함수 :math:`\sin(z_r + i z_i)` 값을 계산합니다. 
    계산 값의 실수부는 :math:`szr` 에 허수부는 :math:`szi` 에 저장됩니다.

.. function:: int gsl_sf_complex_cos_e (double zr, double zi, gsl_sf_result * czr, gsl_sf_result * czi)

    복소 cosine 함수 :math:`\cos(z_r + i z_i)` 값을 계산합니다. 
    계산 값의 실수부는 :math:`czr` 에, 허수부는 :math:`czi` 에 저장됩니다.

.. function:: int gsl_sf_complex_logsin_e (double zr, double zi, gsl_sf_result * lszr, gsl_sf_result * lszi)

    sine 함수의 로그 값 :math:`\log(\sin(z_r + i z_i))` 값을 계산합니다. 
    계산 값의 실수부는 :math:`lszr` 에 허수부는 :math:`lszi` 에 저장됩니다.


쌍곡 함수 (Hyperbolic Trigonometric Functions)
---------------------------------------------------------

.. function:: double gsl_sf_lnsinh (double x)
              int gsl_sf_lnsinh_e (double x, gsl_sf_result * result)

    :math:`\log(\text{sinh}(x))` 값을, :math:`x>0` 에 대해 계산합니다.

.. function:: double gsl_sf_lncosh (double x)
              int gsl_sf_lncosh_e (double x, gsl_sf_result * result)

    주어진 값 :math:`x` 대해, :math:`\log(\text{cosh}(x))` 값을 계산합니다.

좌표 변환 함수 (Conversion Functions)
-----------------------------------------

.. function:: int gsl_sf_polar_to_rect (double r, double theta, gsl_sf_result * x, gsl_sf_result * y)

    극 좌표( :math:`r`  :math:`theta` ) 를 직교 좌표( :math:`x` :math:`y` )로 변환합니다. 
    :math:`x = r \cos(\theta), y= r\sin(\theta)` 관계를 이용합니다.


.. function:: int gsl_sf_rect_to_polar (double x, double y, gsl_sf_result * r, gsl_sf_result * theta)

    직교 좌표( :math:`x` :math:`y` )를 극 좌표( :math:`r` :math:`theta` )로 변환합니다. 
    :math:`x = r \cos(\theta), y= r\sin(\theta)` 관계를 이용합니다. 
    :math:`theta` 는 :math:`[-\pi, \pi]` 의 범위를 가집니다.

각 제한 함수 (Restriction Functions)
-----------------------------------------

.. function:: double gsl_sf_angle_restrict_symm (double theta)
              int gsl_sf_angle_restrict_symm_e (double * theta)

    각 :math:`theta`  값을 :math:`(-\pi, pi]` 범위 내에 있도록 변환합니다.

    .. note::

        실제 :math:`\pi` 값은 :math:`M_PI` 보다 조금 큽니다.따라서, :math:`M_PI` :math:`-M_PI` 이 범위에 포함되어 있습니다.


.. function:: double gsl_sf_angle_restrict_pos (double theta)
              int gsl_sf_angle_restrict_pos_e (double * theta)


    각 :math:`theta`  값을 :math:`(0, 2pi]` 범위 내에 있도록 변환합니다.

    .. note::

        실제 :math:`2\pi` 값은 :math:`2M_PI` 보다 조금 큽니다. 따라서, :math:`2*M_PI` 이 범위에 포함되어 있습니다.

오차 분석을 포함한 삼각 함수 (Trigonometric Functions With Error Estimates)
-----------------------------------------------------------------------------------------

.. function:: int gsl_sf_sin_err_e (double x, double dx, gsl_sf_result * result)

    각 :math:`x` 대해, 버금 절대 오차 :math:`dx` 가 포함된 sine 값 :math:`\sin(x \pm dx)`을 계산합니다. 
    
    .. note::
        
        오차 전파를 계산하기 위해 제공하는 것이기 때문에     오차 관리 함수 형태만으로 제공됩니다.


.. function:: int gsl_sf_cos_err_e (double x, double dx, gsl_sf_result * result)

    각 :math:`x` 대해, 버금 절대 오차 :math:`dx` 포함된 cosine 값 :math:`\cos(x \pm dx)` 을 계산합니다. 

    .. note::
        
        오차 전파를 계산하기 위해 제공하는 것이기 때문에     오차 관리 함수 형태만으로 제공됩니다.



