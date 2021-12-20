

구겐바우어 다항식은 Abramowitz & Stgun의 22단원에 정의되어 있습니다. 
이 다항식은 또 Ultraspherical 다항식으로도 알려져있습니다. 
이 함수들은 헤더 파일 :code:`gsl_sf_gegenbauer.h` 에 정의되어 있습니다.

.. c:function:: double gsl_sf_gegenpoly_1 (double lambda, double x)
                double gsl_sf_gegenpoly_2 (double lambda, double x)
                double gsl_sf_gegenpoly_3 (double lambda, double x)
                int gsl_sf_gegenpoly_1_e (double lambda, double x, gsl_sf_result * result)
                int gsl_sf_gegenpoly_2_e (double lambda, double x, gsl_sf_result * result)
                int gsl_sf_gegenpoly_3_e (double lambda, double x, gsl_sf_result * result)

    구겐바우어 다항식 :math:`C_n^{(\lambda)}(x)` 을 
    :math:`n= 1, 2, 3`  인 경우에 대해, 
    정의식을 이용해 계산합니다.


.. c:function:: double gsl_sf_gegenpoly_n (int n, double lambda, double x)
                int gsl_sf_gegenpoly_n_e (int n, double lambda, double x, gsl_sf_result * result)

    구겐바우어 다항식 :math:`C_n^{(\lambda)}(x)` 
    을 주어진 :math:`n` , :math:`lambda` , 그리고 :math:`x` 에 대해 
    계산합니다. 이때, :math:`\lambda > - \frac{1}{2}. n \geq 0` 이어야 합니다.


.. c:function:: int gsl_sf_gegenpoly_array (int nmax, double lambda, double x, double result_array[])

    구겐바우어 다항식 :math:`C_n^{(\lambda)}(x)`  배열 값을 계산합니다. :math:`n = 0, 1, 2, \dots , nmax`  의 값을 계산하며, :math:`\lambda > - \frac{1}{2}. nmax \geq 0`  의 제약을 가집니다.
