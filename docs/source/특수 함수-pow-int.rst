# 멱함수 (Power Function)

다음의 함수들은 오차 계산과 함께라면, 함수 :math:`gsl_pow_int()` 같습니다. 이 함수들은 헤더 파일 :math:`gsl_sf_pow_int.h` 정의되어 있습니다.


>double **gsl_sf_pow_int**(double *x*, int *n*)<br>
>int **gsl_sf_pow_int_e**(double *x*, int *n*, gsl_sf_result * *result*)

이 함수들은 정수 :math:`n` 대해 :math:`x^n`  의 값을 계산합니다. 이 때, 거듭 제곱은 곱셈 횟수를 최소화해 계산됩니다. 예를 들어서, :math:`x^8`  을 계산하고자 하면, :math:`3` 번의 곱셈을 이용해 :math:`((x^2)^2)^2`  으로 계산합니다. 효율성을 위해서 이 함수는 오버 플로우나 언더 플로우 조건을 검사하지 않습니다. 

다음은 간단한 예제입니다.

.. code-block:: C

    #include <gsl/gsl_sf_pow_int.h>
/* compute 3.0**12 */
double y = gsl_sf_pow_int(3.0, 12);