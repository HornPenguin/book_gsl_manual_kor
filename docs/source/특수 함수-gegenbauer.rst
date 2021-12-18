구겐바우어 함수 (Gegenbauer Functions)
---------------------------------------------

구겐바우어 다항식은 Abramowitz & Stgun의 22단원에 정의되어 있습니다. 이 다항식은 또 Ultraspherical 다항식으로도 알려져있습니다. 이 함수들은 헤더 파일  ``gsl_sf_gegenbauer.h``  정의되어 있습니다.

>double **gsl_sf_gegenpoly_1**(double *lambda*, double *x*) <br>
>double **gsl_sf_gegenpoly_2**(double *lambda*, double *x*) <br>
>double **gsl_sf_gegenpoly_3**(double *lambda*, double *x*) <br>
>int **gsl_sf_gegenpoly_1_e**(double *lambda*, double *x*, gsl_sf_result * *result*) <br>
>int **gsl_sf_gegenpoly_2_e**(double *lambda*, double *x*, gsl_sf_result * *result*) <br>
>int **gsl_sf_gegenpoly_3_e**(double *lambda*, double *x*, gsl_sf_result * *result*) 

이 함수들은 구겐바우어 다항식  :math:`C_n^{(\lambda)}(x)` 을  :math:`n= 1, 2, 3` 인 경우에 대해, 정의식을 이용해 계산합니다.


>double **gsl_sf_gegenpoly_n**(int *n*, double *lambda*, double *x*) <br>
>int **gsl_sf_gegenpoly_n_e**(int *n*, double *lambda*, double *x*, gsl_sf_result * *result*)

이 함수들은 구겐바우어 다항식  :math:`C_n^{(\lambda)}(x)` 을 주어진  ``n``  ``lambda``   ``x``  대해 계산합니다. 이때,  :math:`\lambda > - \frac{1}{2}. n \geq 0` 이어야 합니다.


> int **gsl_sf_gegenpoly_array**(int *nmax*, double *lambda*, double *x*, double *result_array*[])

이 함수는 구겐바우어 다항식 :math:`C_n^{(\lambda)}(x)`  배열 값을 계산합니다.  :math:`n = 0, 1, 2, \dots , nmax` 의 값을 계산하며,  :math:`\lambda > - \frac{1}{2}. nmax \geq 0` 의 제약을 가집니다.
