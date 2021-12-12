# 싱크트론 함수 (Synchrotron Functions)

이 단원의 함수들은  ``gsl_sf_sychrotron.h`` 해더 파일에 기술되어 있습니다.

>double **gsl_sf_synchrotron_1**(double *x*) <br>
>int **gsl_sf_synchrotron_1_e**(double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`x \geq 0` 에 대해, 1차 싱크로트론 함수  :math:`x \int_x^\infty K_{5/3} \, dt` 를 계산합니다.

>double **gsl_sf_synchrotron_2**(double *x*)<br>
>int **gsl_sf_synchrotron_2_e**(double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`x \geq 0` 에 대해, 2차 싱크로트론 함수  :math:`x \int_x^\infty K_{2/3} \, dt` 를 계산합니다.

