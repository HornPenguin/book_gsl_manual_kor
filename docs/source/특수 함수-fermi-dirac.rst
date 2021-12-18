

이 함수들은 헤더 파일  ``gsl_sf_fermi_dirac.h``  정의되어 있습니다.

완비 페르미-디렉 적분 (Complete Fermi-Dirac Integrals)
-------------------------------------------------------------

완비 페르미 디렉 적분  :math:`F_j(x)` 는 다음과 같이 정의됩니다.

 :math:`$F_j(x) := \frac{1}{\Gamma(j+1)} \int_0^\infty \frac{t^j}{(\exp(t-x)+1)} dt` $

다른 문헌에서 정규화 계수 없이 표현되기도 합니다.

>double **gsl_sf_fermi_dirac_m1**(double *x*)<br>
>int **gsl_sf_fermi_dirac_m1_e**(double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`j=-1` 인 완비 페르미 디렉 적분 값을 계산합니다. 이 값은  :math:`F_{-1}(x) = e^x/(1+e^x)` 로 주어집니다.

>double **gsl_sf_fermi_dirac_0**(double *x*)<br>
>int **gsl_sf_fermi_dirac_0_e**(double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`j=0` 인 완비 페르미 디렉 적분 값을 계산합니다. 이 값은  :math:`F_{0}(x) = \ln(1+e^x)` 로 주어집니다.

>double **gsl_sf_fermi_dirac_1**(double *x*)<br>
>int **gsl_sf_fermi_dirac_1_e**(double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`j=-1` 인 완비 페르미 디렉 적분 값을 계산합니다. 이 값은  :math:`F_{1}(x) = \int_0^\infty(t / (\exp(t-x)+1) dt` 로 주어집니다.

>double **gsl_sf_fermi_dirac_2**(double *x*)<br>
>int **gsl_sf_fermi_dirac_2_e**(double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`j=2` 인 완비 페르미 디렉 적분 값을 계산합니다. 이 값은  :math:`F_{2}(x) = (1/2) \int_0^\infty(t^2 / (\exp(t-x)+1) dt` 로 주어집니다.

>double **gsl_sf_fermi_dirac_int**(int *j*, double *x*)<br>
>int gsl_sf_fermi_dirac_int_e(int *j*, double *x*, gsl_sf_result * *result*)

이 함수들은 일반 완비 페르미 디렉 적분 값을 계산합니다. 이 값은  :math:`F_{j}(x) = ((1/\Gamma(j+1)) \int_0^\infty (t^j / (\exp(t-x)+1) dt` 로 주어집니다.


>double **gsl_sf_fermi_dirac_mhalf**(double *x*)<br>
>int **gsl_sf_fermi_dirac_mhalf_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 완비 페르미-디렉 적분  :math:`F_{-1/2}(x)`  값을 계산합니다.

>double **gsl_sf_fermi_dirac_half**(double *x*)<br>
>int **gsl_sf_fermi_dirac_half_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 완비 페르미-디렉 적분  :math:`F_{1/2}(x)`  값을 계산합니다.


>double **gsl_sf_fermi_dirac_3half**(double *x*)<br>
>int **gsl_sf_fermi_dirac_3half_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 완비 페르미-디렉 적분  :math:`F_{3/2}(x)`  값을 계산합니다.

비완비 페르미-디렉 적분 (Incomplete Fermi-Dirac Integrals)
-------------------------------------------------------------

비완비 페르미-디렉 함수  :math:`F_j(x,b)` 는 다음과 같이 정의됩니다.

 :math:`$ F_j(x,b) := \frac{1}{\Gamma (j+1)} \int_b^\infty \frac{t^j}{\exp(t-x)+1} dt` $

>double **gsl_sf_fermi_dirac_inc_0**(double *x*, double *b*)<br>
>int **gsl_sf_fermi_dirac_inc_0_e**(double *x*, double *b*, gsl_sf_result * *result*)

이 함수들은  :math:`0`  차수의 비완비 페르미-디렉 적분,  :math:`F_) (x,b) = \ln (1+ e^{b-x}) - (b-x)` 값을 계산합니다.