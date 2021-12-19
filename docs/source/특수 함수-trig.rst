
# 삼각 함수 (Trigonometric Functions)

본 라이브러리는 여러 플랫폼에서 일관적인 코드 작성과 신뢰할 수 있는 오류 측정을 위해 자체적인 삼각 함수를 포함하고 있습니다. 이 함수들은 헤더파일 :math:`gsl_sf_trig.h` 정의되어 있습니다.

삼각 함수 (Circular Trigonometric Functions)
-------------------------

>double **gsl_sf_sin**(double *x*)<br>
>int **gsl_sf_sin_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 sine 함수 :math:`\sin(x)`  를 계산합니다.

>double **gsl_sf_cos**(double *x*)<br>
>int **gsl_sf_cos_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 cosine 함수 :math:`\cos(x)`  를 계산합니다.

>double **gsl_sf_hypot**(double *x*, double y)<br>
>int **gsl_sf_hypot_e**(double *x*, double y, gsl_sf_result * *result*)

이 함수들은 오버 플로우와 언더 플로우 없는 :math:`\sqrt{x^2+y^2}` 값을 계산합니다.

>double **gsl_sf_sinc**(double *x*)<br>
>int **gsl_sf_sinc_e**(double *x*, gsl_sf_result * *result*)

이 함수는 주어진 :math:`x`  에 대해, :math:`\text{sinc}(x) = \sin(\pi x)/(\pi x)` 값을 계산합니다.

복소 삼각 함수 (Trigonometric Functions for Complex Arguments)
-------------------------

>int **gsl_sf_complex_sin_e**(double *zr*, double *zi*, gsl_sf_result * *szr*, gsl_sf_result * *szi*)

이 함수는 복소 sine 함수 :math:`\sin(z_r + i z_i)` 값을 계산합니다. 계산 값의 실수부는 :math:`szr` 허수부는 :math:`szi` 저장됩니다.

>int **gsl_sf_complex_cos_e**(double *zr*, double *zi*, gsl_sf_result * *czr*, gsl_sf_result * *czi*)

이 함수는 복소 cosine 함수 :math:`\cos(z_r + i z_i)` 값을 계산합니다. 계산 값의 실수부는 :math:`czr` 허수부는 :math:`czi` 저장됩니다.

>int **gsl_sf_complex_logsin_e**(double *zr*, double *zi*, gsl_sf_result * *lszr*, gsl_sf_result * *lszi*)

이 함수는 sine 함수의 로그 값 :math:`\log(\sin(z_r + i z_i))`  을 계산합니다. 계산 값의 실수부는 :math:`lszr`  , 허수부는 :math:`lszi` 저장됩니다.


쌍곡 함수 (Hyperbolic Trigonometric Functions)
-------------------------

>double **gsl_sf_lnsinh**(double *x*)<br>
>int **gsl_sf_lnsinh_e**(double *x*, gsl_sf_result * *result*)

이 함수는 :math:`\log(\text{sinh}(x))` 값을, :math:`x>0`  에 대해 계산합니다.

>double **gsl_sf_lncosh**(double *x*)<br>
>int **gsl_sf_lncosh_e**(double *x*, gsl_sf_result * *result*)

이 함수는 주어진 값 :math:`x` 대해, :math:`\log(\text{cosh}(x))` 값을 계산합니다.

좌표 변환 함수 (Conversion Functions)
-------------------------

>int **gsl_sf_polar_to_rect**(double *r*, double *theta*, gsl_sf_result * *x*, gsl_sf_result * *y*)

이 함수는 극 좌표( :math:`r`  :math:`theta`  를 직교 좌표( :math:`x` :math:`y`  로 변환합니다. :math:`x = r \cos(\theta), y= r\sin(\theta)`  .


>int **gsl_sf_rect_to_polar**(double *x*, double *y*, gsl_sf_result * *r*, gsl_sf_result * *theta*)

이 함수는 직교 좌표( :math:`x` :math:`y`  를 극 좌표( :math:`r` :math:`theta`  로 변환합니다. :math:`x = r \cos(\theta), y= r\sin(\theta)`  . :math:`theta` :math:`[-\pi, \pi]`  의 범위를 가집니다.

각 제한 함수 (Restriction Functions)
-------------------------

>double **gsl_sf_angle_restrict_symm**(double *theta*)<br>
>int **gsl_sf_angle_restrict_symm_e**(double * *theta*)

이 함수들은 각 :math:`theta`  값을 :math:`(-\pi, pi]` 범위 내에 있도록 변환합니다.

유의점: 실제 :math:`\pi` 값은 :math:`M_PI`  다 조금 큽니다.따라서, :math:`M_PI` :math:`-M_PI` 이 범위에 포함되어 있습니다.


>double **gsl_sf_angle_restrict_pos**(double *theta*)<br>
>int **gsl_sf_angle_restrict_pos_e**(double * *theta*)

이 함수들은 각 :math:`theta`  값을 :math:`(0, 2pi]` 범위 내에 있도록 변환합니다.

유의점: 실제 :math:`2\pi` 값은 :math:`2M_PI`  다 조금 큽니다. 따라서, :math:`2*M_PI` 이 범위에 포함되어 있습니다.

오차 분석을 포함한 삼각 함수 (Trigonometric Functions With Error Estimates)
-------------------------


>int **gsl_sf_sin_err_e**(double *x*, double *dx*, gsl_sf_result * *result*)

이 함수는 각 :math:`x` 대해, 버금 절대 오차 :math:`dx` 포함된 sine 값 :math:`\sin(x \pm dx)`  을 계산합니다. 유의점: 이 함수는 오차 관리 함수 형태만으로 제공됩니다. 이는 이 함수가 오차 전파를 계산하기 위해 제공하는 것이기 때문입니다.

>int **gsl_sf_cos_err_e**(double *x*, double *dx*, gsl_sf_result * *result*)

이 함수는 각 :math:`x` 대해, 버금 절대 오차 :math:`dx` 포함된 cosine 값 :math:`\cos(x \pm dx)`  을 계산합니다. 유의점: 이 함수는 오차 관리 함수 형태만으로 제공됩니다. 이는 이 함수가 오차 전파를 계산하기 위해 제공하는 것이기 때문입니다.



