# 프사이(디감마) 함수 (Psi (Digamma) Function)

차수  :math:`n` 의 극 감마 함수는 다음과 같이 정의됩니다.

 :math:`$\psi^{(n)} (x) = (\frac{d}{dx})^n \psi(x) = (\frac{d}{dx})^{n+1} \log(\Gamma(x))` $

 :math:`\psi(x) = \Gamma'(x)/\Gamma(x)` 는 Digamma 함수로 알려져 있습니다. 이 단원의 함수들은 헤더 파일  ``gsl_sf_psi.h``  기술되어 있습니다.

Digamma 함수 (Digamma Function)
-------------------------

>double **gsl_sf_psi_int**(int *n*)<br>
>int **gsl_sf_psi_int_e**(int *n*, gsl_sf_result * *result*)


이 함수들은 digamma 함수  :math:`\psi(n)`  값을 주어진 양의 정수  ``n``  대해 계산합니다. digamma 함수는 프사이(Psi) 함수라고도 불립니다.


>double **gsl_sf_psi**(double *x*)<br>
>int **gsl_sf_psi_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 digamma 함수  :math:`\psi(x)` 를 주어진 값  ``x``  대해 계산합니다. 이때,  :math:`x \neq 0`  입니다.

>double **gsl_sf_psi_1piy**(double *y*)<br>
>int **gsl_sf_psi_1piy_e**(double *y*, gsl_sf_result * *result*)

이 함수들은  :math:`1+iy`  선 위에서의 digamma 함수의 실수부  :math:`\mathfrak{R}[\psi(1+iy)]` 를 계산합니다.

Trigamma 함수 (Trigamma Function)
-------------------------

>double **gsl_sf_psi_1_int**(int *n*)<br>
>int **gsl_sf_psi_1_int_e**(int *n*, gsl_sf_result * *result*)

이 함수들은 Trigamma 함수  :math:`\psi'(n)` 을 주어진 양의 정수  ``n``  대해 계산합니다.


>double **gsl_sf_psi_1**(double *x*)<br>
>int **gsl_sf_psi_1_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 Trigamma 함수  :math:`\psi'(x)` 를 주어진 값  ``x``  대해 계산합니다.

Polygamma 함수 (Polygamma Function)
-------------------------

>double **gsl_sf_psi_n**(int *n*, double *x*)<br>
>int **gsl_sf_psi_n_e**(int *n*, double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`n \geq 0, x>0` 인  :math:`n,x` 에 대해, polygamma 함수  :math:`\psi^{(n)}(x)` 를 계산합니다. 
