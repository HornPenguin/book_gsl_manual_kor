# 에르미트 다항식과 함수 (Hermite Polynomials and Functions)

에르미트 다항식과 함수는 Abramowitz & Stegunm Chapter 22 와 Szego, Gabor (1939, 1957, 1967) Orthogonal Polynomials, American Mathematical Society에 기술되어 있습니다. 본 단원의 함수들은 헤더 파일  ``gsl_sf_hermite.h``  정의 되었습니다.

에르미트 다항식(Hermite Polynomials)
-------------------------

에르미트 다항식은 두 가지 형태가 존재합니다.  :math:`H_n(x)` 는 물리학에서 사용하는 형태이고,  :math:`H_{e_n}(x)` 는 확률론에서 사용하는 형태입니다. 

 :math:`$H_n(x) = (-1)^n e^{x^2} (\frac{d}{dx})^n e^{-x^2}` $
 :math:`$H_{e_n}(x) = (-1)^n e^{x^2/2} (\frac{d}{dx})^n e^{-x^2/2}` $

이 둘은 다음의 관계를 가지고,

 :math:`$H_n(x) = 2^{\frac{n}{2}}H_{e_n}(\sqrt{2}x)` $
 :math:`$H_{e_n}(x) = 2^{-\frac{n}{2}}H_n(\frac{x}{\sqrt{2}})` $

다음과 같은 미분 방정식을 만족합니다.

 :math:`$H_{n}''(x) -2xH_{n}'(x) + 2nH_{n}(x)=0` $
 :math:`$H_{e_n}''(x) -xH_{e_n}'(x) + nH_{e_n}(x)=0` $

>double **gsl_sf_hermite**(const int *n*, const double *x*)<br>
>int **gsl_sf_hermite_e**(const int *n*, const double *x*, gsl_sf_result * *result*)

이 함수는  :math:`H_n(x)`  형태의 에르미트 다항식을 주어진 차수  ``n``  변수  ``x``  대해 계산합니다. 오버플로우가 감지되면, 오류 관리자를 호출하지 않고  ``GSL_EOVERFLW``  반환합니다.

>int **gsl_sf_hermite_array**(const int *nmax*, const double *x*, double * *result_array*)

이 함수는  ``nmax`` 이하의 차수를 가지는 모든  :math:`H_n(x)`  형태의 에르미트 다항식을 주어진 변수  ``x``  대해 계산합니다. 결과는  ``result_array``  저장됩니다.

>double **gsl_sf_hermite_series**(const int *n*, const double *x*, const double * *a*)<br>
>int **gsl_sf_hermite_series_e**(const int *n*, const double *x*, const double * *a*, gsl_sf_result * *result*)

이 함수들은  :math:`\sum_{j=0}^n a_j H_j (x)`  급수 값을 Clenshaw 알고리즘을 이용해 계산합니다.

>double **gsl_sf_hermite_prob**(const int *n*, const double *x*)<br>
>int **gsl_sf_hermite_prob_e**(const int *n*, const double *x*, gsl_sf_result * *result*)

이 함수는   :math:`H_{e_n}(x)`  형태의 에르미트 다항식을 주어진 차수  ``n``  변수  ``x``  대해 계산합니다. 오버플로우가 감지되면, 오류 관리자를 호출하지 않고  ``GSL_EOVERFLW``  반환합니다.

>int **gsl_sf_hermite_prob_array**(const int *nmax*, const double *x*, double * *result_array*)

이 함수는  ``nmax`` 이하의 차수를 가지는 모든  :math:`H_{e_n}(x)`  형태의 에르미트 다항식을 주어진 변수  ``x``  대해 계산합니다. 결과는  ``result_array``  저장됩니다.


>double **gsl_sf_hermite_prob_series**(const int *n*, const double *x*, const double * *a*)<br>
>int **gsl_sf_hermite_prob_series_e**(const int *n*, const double *x*, const double * *a*, gsl_sf_result * *result*)

이 함수들은  :math:`\sum_{j=0}^n a_j H_{e_j} (x)`  급수 값을 Clenshaw 알고리즘을 이용해 계산합니다.


에르미트 다항식의 도함수 (Derivatives of Hermite Polynomials)
-------------------------

>double **gsl_sf_hermite_deriv**(const int *m*, const int *n*, const double *x*)<br>
>int gsl_sf_hermite_deriv_e(const int *m*, const int *n*, const double *x*, gsl_sf_result * *result*)

이 함수들은  ``n`` 차수의 에르미트 다항식  :math:`H_n(x)` 의  ``m``  도함수 값을 주어진 변수 ``x``  대해 계산합니다.

>int **gsl_sf_hermite_array_deriv**(const int *m*, const int *nmax*, const double *x*, double * *result_array*)

 이 함수는  :math:`0, \dots, nmax`  차수의 모든 에르미트 다항식  :math:`H_n(x)` 의  ``m``  도함수 값을 주어진 변수  ``x``  대해 계산합니다.   :math:`d^m / dx^m H_n(x)` 의 값은  ``result_array[n]``  저장됩니다. 계산 결과가 저장되는  ``result_array``  최소  ``nmax+1`` 이상의 길이를 가져야 합니다.

>int **gsl_sf_hermite_deriv_array**(const int *mmax*, const int *n*, const double *x*, double * *result_array*)

 이 함수는  ``n``  차수를 가지는 에르미트 다항식  :math:`H_n(x)` 의 모든  :math:`0, \dots, mmax` 차 도함수 값을 주어진 변수  ``x``  대해 계산합니다.   :math:`d^m / dx^m H_n(x)` 의 값은  ``result_array[m]]``  저장됩니다. 계산 결과가 저장되는  ``result_array``  최소  ``mmax+1`` 이상의 길이를 가져야 합니다.


>double **gsl_sf_hermite_prob_deriv**(const int *m*, const int *n*, const double *x*)<br>
>int **gsl_sf_hermite_prob_deriv_e**(const int *m*, const int *n*, const double *x*, gsl_sf_result * *result*)

이 함수들은  ``n`` 차수의 에르미트 다항식  :math:`H_{e_n}(x)` 의  ``m``  도함수 값을 주어진 변수 ``x``  대해 계산합니다.

>int **gsl_sf_hermite_prob_array_deriv**(const int *m*, const int *nmax*, const double *x*, double * *result_array*)

 이 함수는  ``n``  차수를 가지는 에르미트 다항식  :math:`H_{e_n}(x)` 의 모든  :math:`0, \dots, mmax` 차 도함수 값을 주어진 변수  ``x``  대해 계산합니다.   :math:`d^m / dx^m H_{e_n}(x)` 의 값은  ``result_array[m]]``  저장됩니다. 계산 결과가 저장되는  ``result_array``  최소  ``mmax+1`` 이상의 길이를 가져야 합니다.



>int **gsl_sf_hermite_prob_deriv_array**(const int *mmax*, const int *n*, const double *x*, double * *result_array*)

 이 함수는  ``n``  차수를 가지는 에르미트 다항식  :math:`H_{e_n}(x)` 의 모든  :math:`0, \dots, mmax` 차 도함수 값을 주어진 변수  ``x``  대해 계산합니다.   :math:`d^m / dx^m H_{e_n}(x)` 의 값은  ``result_array[m]]``  저장됩니다. 계산 결과가 저장되는  ``result_array``  최소  ``mmax+1`` 이상의 길이를 가져야 합니다.


에르미트 함수 (Hermite Functions)
-------------------------

에르미트 함수는 다음과 같이 정의됩니다.

 :math:`$\psi_n(x) = \frac{1}{(2^n n! \sqrt{\pi})^{\frac{1}{2}}} e^{- \frac{x^2}{2}} H_n(x)` $

이 함수는 양자 역학에 나오는 슈뢰딩거 방정식의 조화 진동자 형태를 만족합니다.

 :math:`$\psi_n''(x) + (2n+1-x^2)\psi_n(x) =0` $

이 함수들은 직교하므로 다음을 만족하고,

 :math:`$\int_{-\infty}^{\infty} \psi_m(x)\psi_n(x) \, dx = \delta_{mn}` $

 :math:`L^2 (\mathbb{R})`  공간의 직교 기저를 형성합니다. 에르미트 함수들은 연속 푸리에 변환의 고유 함수이기도 합니다. GSL은 에르미트 함수를 계산하는 두 가지 방법을 제공합니다. 첫 번째는 수학적으로 정의된  :math:`3`  개항의 재귀 관계를 이용합니다. 이 방법은  :math:`O(n)` 의 계산 복잡도를 가지고 가장 정확합니다. 두 번째는 코시 적분 접근 방법을 이용한 방법입니다. 이는 (Bunck, 2009)에 소개 되었으며,  :math:`O(\sqrt{n})` 의 계산복잡도를 가집니다. 정확도를 조금 희생하지만  :math:`n`  값이 클 수록, 기존 방법에 비해 속도에 큰 이점이 있습니다.

>double **gsl_sf_hermite_func**(const int *n*, const double *x*)<br>
>int **gsl_sf_hermite_func_e**(const int *n*, const double *x*, gsl_sf_result * *result*)


이 함수들은 차수  ``n``  에르미트 함수  :math:`\psi_n(x)` 를 주어진 변수  ``x``  대해 계산합니다. 이 방법은 재귀 관계를 이용하며,  :math:`O(n)` 의 계산 복잡도를 가집니다.


>double **gsl_sf_hermite_func_fast**(const int *n*, const double *x*)<br>
>int **gsl_sf_hermite_func_fast_e**(const int *n*, const double *x*, gsl_sf_result * *result*)

이 함수들은 차수  ``n``  에르미트 함수  :math:`\psi_n(x)` 를 주어진 변수  ``x``  대해 계산합니다. 이 방법은 (Bunck, 2009)의 코시 적분을 이용하며,  :math:`O(\sqrt{n})` 의 계산 복잡도를 가집니다.


>int **gsl_sf_hermite_func_array**(const int *nmax*, const double *x*, double * *result_array*)

이 함수는  :math:`n=0, \dots ,nmax` 의 차수를 가지는 에르미트 함수  :math:`\psi_n(x)` 를 주어진 변수  ``x``  대해, 재귀적 방법을 이용해 계산합니다. 계산 결과는  ``result_array``  저장되며 최소  ``nmax+1`` 이상의 길이를 가져야 합니다.

>double **gsl_sf_hermite_func_series**(const int *n*, const double *x*, const double * *a*)<br>
>int **gsl_sf_hermite_func_series_e**(const int *n*, const double *x*, const double * *a*, gsl_sf_result * *result*)

이 함수들은  :math:`\sum_{j=0}^n a_j \psi_j (x)`  급수를 계산합니다.  :math:`\psi_j` 는  :math:`j` 의 차수를 가지는 에르미트 함수를 의미하며, Clenshaw 알고리즘을 이용합니다.


에르미트 함수의 도함수 (Derivatives of Hermite Functions)
-------------------------

>double **gsl_sf_hermite_func_der**(const int *m*, const int *n*, const double *x*)<br>
>int **gsl_sf_hermite_func_der_e**(const int *m*, const int *n*, const double *x*, gsl_sf_result * *result*)

이 함수들은  ``n`` 수의 에르미트 함수  :math:`\psi_n(x)` 의  ``m``  도함수를 주어진  ``x``  대해 계산합니다.


에르미트 함수와 다항식의 근 (Zeros of Hermite Polynomials and Hermite Functions)
-------------------------

이 함수들은 차수  :math:`n` 을 가지는 에르미트 함수와 다항식의  :math:`s`  번째 근을 계산합니다. 각 근들이 원점을 기준으로 대칭이기 때문에, 양수인 근들만 계산됩니다. 인덱스는  :math:`1` 부터 시작해서 오름차순으로 배열됩니다. 홀수 차수의 다항식 만이  :math:`0` 에서  ``0`` 째 근을 가집니다. 해당 값은 항상  :math:`0` 입니다.

>double **gsl_sf_hermite_zero**(const int *n*, const int *s*)<br>
>int **gsl_sf_hermite_zero_e**(const int *n*, const int *s*, gsl_sf_result * *result*)

이 함수들은  ``n`` 수의 에르미트 다항식  :math:`H_n(x)` 의  ``s`` 째 근을 계산합니다.


>double **gsl_sf_hermite_prob_zero**(const int *n*, const int *s*)<br>
>int **gsl_sf_hermite_prob_zero_e**(const int *n*, const int *s*, gsl_sf_result * *result*)

이 함수들은  ``n`` 수의 에르미트 다항식  :math:`H_{e_n}(x)` 의  ``s`` 째 근을 계산합니다.

>double **gsl_sf_hermite_func_zero**(const int *n*, const int *s*)<br>
>int **gsl_sf_hermite_func_zero_e**(const int *n*, const int *s*, gsl_sf_result * *result*)

이 함수들은  ``n`` 차수의 에르미트 함수  :math:`\psi_n(x)` 의  ``s`` 번째 근을 계산합니다.
