.. index:: Laguerre function
.. index:: 라게르 다항식


일반화 된 라게르 다항식(다른 이름으로 버금 라게르 다항식이 있습니다)은 합류 초기하 함수(confluent hypergeometric function)로 정의됩니다.

.. math:: 
    
    L_n^a (x) = \frac{(a+1)_n}{n!} {}_1F_1(-n,a+1,x)

:math:`(a)_n` 는 포흐하머 기호(Pochhammer symbol)입니다. 
이들은 일반적인 라게르 다항식 :math:`L_n(x)` 과 다음의 관계를 가집니다. 

.. math::
    
    L_n^0(x) = L_n(x)\\  
    L_n^k(x) = (-1)^k (d^k /d x^k)L_{(n+k)}(x)

더 자세한 정보는  Abramowitz & Strgun, Chapter 22를 참조할 수 있습니다.

이 단원에서 기술된 함수들은 헤더 파일 :code:`gsl_sf_laguerre.h` 에 정의되어 있습니다.

.. c:function:: double gsl_sf_laguerre_1 (double a, double x)
                double gsl_sf_laguerre_3 (double a, double x)
                double gsl_sf_laguerre_2 (double a, double x)
                int gsl_sf_laguerre_1_e (double a, double x, gsl_sf_result * result)
                int gsl_sf_laguerre_2_e (double a, double x, gsl_sf_result * result)
                int gsl_sf_laguerre_3_e (double a, double x, gsl_sf_result * result)

    일반화된 라게르 다항식 :math:`L_1^a (x), L_2^a (x), L_3^a (x)` 을 수학 정의식을 이용해 계산합니다.

.. c:function:: double gsl_sf_laguerre_n (const int n, const double a, const double x)
              
    일반화된 라게르 다항식 :math:`L_n^a(x)` 를 :math:`a > -1, n \geq 0` 인 경우를 계산합니다.
