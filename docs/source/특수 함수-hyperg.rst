초기하 함수 (Hypergeometric Functions)
---------------------------------------------

초기하 함수들은 Abramowitz& Stegun의 13, 15 단원의 기술을 기반으로 작성되었습니다. 이 함수들은 헤더 파일  ``gsl_sf_hyperg.h``  정의 되어있습니다,


>double **gsl_sf_hyperg_0F1**(double *c*, double *x*)<br>
>int **gsl_sf_hyperg_0F1_e**(double *c*, double *x*, gsl_sf_result * *result*)


이 함수들은 초기하 함수 

 :math:`$_0F_1(c,x)` $

를 계산합니다.


>double **gsl_sf_hyperg_1F1_int**(int *m*, int *n*, double *x*)<br>
>int **gsl_sf_hyperg_1F1_int_e**(int *m*, int *n*, double *x, gsl_sf_result * *result*)


이 함수들은 합류 초기하 함수(confluent hypergeometric)

 :math:`$_1F_1(m,n,x) = M(m,n,x)` $

를 정수 인자  ``m``   ``n``  따라 계산합니다.


> double **gsl_sf_hyperg_1F1**(double *a*, double *b*, double *x*)<br>
> int **gsl_sf_hyperg_1F1_e**(double *a*, double *b*, double *x*, gsl_sf_result * *result*)

이 함수들은 합류 초기하 함수

 :math:`$_1F_1(a,b,x) = M(a,b,x)` $

를 일반 인자  ``a``   ``b``  따라 계산합니다.


>double **gsl_sf_hyperg_U_int**(int *m*, int *n*, double *x*)<br>
>int **gsl_sf_hyperg_U_int_e**(int *m*, int *n*, double *x*, gsl_sf_result * *result*)


이 함수들을 합류 초기하 함수  :math:`U(m,n,x)` 를 정수 인자  ``m``   ``n``  대해 계산합니다.


>int **gsl_sf_hyperg_U_int_e10_e**(int *m*, int *n*, double *x*, gsl_sf_result_e10 * *result*)

이 함수들을 합류 초기하 함수  :math:`U(m,n,x)` 를 정수 인자  ``m``   ``n``  대해 계산하고 확장된 구간에 대해,  ``gsl_sf_result_e10`` 형의 값을 반환합니다.

>double **gsl_sf_hyperg_U**(double *a*, double *b*, double *x*)<br>
>int **gsl_sf_hyperg_U_e**(double *a*, double *b*, double *x*, gsl_sf_result * *result*)


이 함수들을 합류 초기하 함수  :math:`U(a,b,x)` 를 계산합니다.

>int **gsl_sf_hyperg_U_e10_e**(double *a*, double *b*, double *x*, gsl_sf_result_e10 * *result*)


이 함수들을 합류 초기하 함수  :math:`U(a,b,x)` 를 계산하고 확장된 구간에 대해  ``gsl_sf_result_e10`` 형의 값을 반환합니다.


>double **gsl_sf_hyperg_2F1**(double *a*, double *b*, double *c*, double *x*)<br>
>int **gsl_sf_hyperg_2F1_e**(double *a*, double *b*, double *c*, double *x*, gsl_sf_result * *result*)

이 함수들은 구간  :math:`\|x\|<1` 에 대해, 가우스 초기하 함수

 :math:`$_2F_1(a,b,c,x) = F(a,b,c,x)` $

의 값을 계산합니다. 만약, 인자  :math:`(a,b,c,x)` 가 특이점(singular point)에 너무 가깝다면, 급수 근사가 너무 느려지게 되고 함수는 오류 값  ``GSL_EMAXITER``  반환합니다. 이러한 지점은  :math:`x=1` ,  :math:`c-a-b=m, m \in \mathbf{Z}`  구간에서 발생합니다.  


>double **gsl_sf_hyperg_2F1_conj**(double *aR*, double *aI*, double *c*, double *x*)<br>
>int **gsl_sf_hyperg_2F1_conj_e**(double *aR*, double *aI*, double *c*, double *x*, gsl_sf_result * *result*)

이 함수들은 구간  :math:`\|x\|<1` 에 대해, 가우스 초기하 함수

 :math:`$_2F_1 (a_R + i a_I , aR-iaI, c, x)` $

의 복소수 인자 값을 계산합니다.

>double **gsl_sf_hyperg_2F1_renorm**(double *a*, double *b*, double *c*, double *x*)<br>
>int **gsl_sf_hyperg_2F1_renorm_e**(double *a*, double *b*, double *c*, double *x*, gsl_sf_result * *result*)
 
이 함수들은 구간  :math:`\|x\|<1` 에 대해, 재규격화 된 가우스 초기하 함수 

 :math:`$\frac{_2F_1(a,b,c,x)}{\Gamma(c)}` $

의 값을 계산합니다.

 
>double **gsl_sf_hyperg_2F1_conj_renorm**(double *aR*, double *aI*, double *c*, double *x*)<br>
>int **gsl_sf_hyperg_2F1_conj_renorm_e**(double *aR*, double *aI*, double *c*, double *x*, gsl_sf_result * *result*)

 
이 함수들은 구간  :math:`\|x\|<1` 에 대해, 재규격화 된 가우스 초기하 함수 

 :math:`$\frac{_2F_1(a_R + ia_I,a_R - i a_I,c,x)}{\Gamma(c)}` $

의 값을 계산합니다.
 
>double **gsl_sf_hyperg_2F0**(double *a*, double *b*, double *x*)<br>
>int **gsl_sf_hyperg_2F0_e**(double *a*, double *b*, double *x*, gsl_sf_result * *result*)

이 함수들은 초기하 함수

 :math:`$_2F_0(a,b,x)` $
를 계산합니다.

급수 표현은 발산하는 초기하 급수입니다. 하지만,  :math:`x<0`  이라면 다음을 얻을 수 있습니다.

 :math:`$_2F_0 (a,b,x) = (-\frac{1}{x})^a U(a, 1+a, -b,- \frac{1}{x})` $
