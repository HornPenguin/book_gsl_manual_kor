# 운송 함수 (Transport Functions)

운송 함수 :math:`J(n,x)`  는 다음과 같이 적분으로 정의됩니다.

 :math:`$J(n,x) = \int_0^x \frac{t^ne^t}{(e^t -1)^2} \, dx` $

이 함수들은 헤더 파일 :math:`gsl_sf_transport.h` 정의되어 있습니다.

>double **gsl_sf_transport_2**(double *x*)<br>
>int **gsl_sf_transport_2_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 운송 함수 :math:`J(2,x)`  의 값을 계산합니다.

>double **gsl_sf_transport_3**(double *x*)<br>
>int **gsl_sf_transport_3_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 운송 함수 :math:`J(3,x)`  의 값을 계산합니다.


>double **gsl_sf_transport_4**(double *x*)<br>
>int **gsl_sf_transport_4_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 운송 함수 :math:`J(4,x)`  의 값을 계산합니다.

>double **gsl_sf_transport_5**(double *x*)<br>
>int **gsl_sf_transport_5_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 운송 함수 :math:`J(5,x)`  의 값을 계산합니다.
