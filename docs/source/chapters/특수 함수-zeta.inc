
리만 제타 함수 (Riemann Zeta Function)
----------------------------------------------

리만 제타 함수는 다음과 같이 무한 급수로 정의됩니다.

.. math::
    
    \zeta (s) = \sum_{k=1}^\infty k^{-s}

.. c:function:: double gsl_sf_zeta_int (int n)
                int gsl_sf_zeta_int_e (int n, gsl_sf_result * result)

    정수 :math:`n` 대한 리만 제타 함수 :math:`\zeta(n)` 의 값을 계산합니다. 
    :math:`n \neq 1` 이어야 합니다.

.. c:function:: double gsl_sf_zeta (double s)
                int gsl_sf_zeta_e (double s, gsl_sf_result * result)

    임의의 수 :math:`s` 대해 리만 제타 함수 :math:`\zeta(s)` 값을 계산합니다. 
    위 함수와 마찬가지로 :math:`s \neq 1` 이어야 합니다.

리만 제타 함수 -1 (Riemann Zeta Function Minus One)
-------------------------------------------------------------------

큰 양수 값에 대해, 리만 제타함수는 1로 수렴하게 됩니다. 이 경우에 1이 아닌 부분의 값이 빈번히 사용되므로, 라이브러리에서는 이를 위한 함수를 제공합니다.

.. c:function:: double gsl_sf_zetam1_int (int n)
                int gsl_sf_zetam1_int_e (int n, gsl_sf_result * result)

    정수 :math:`n` 대한 :math:`\zeta(n)-1` 의 값을 계산합니다. 
    :math:`n \neq 1` 이어야 합니다.

.. c:function:: double gsl_sf_zetam1 (double s)
                int gsl_sf_zetam1_e (double s, gsl_sf_result * result)


    임의의 수 :math:`s` 대해 :math:`\zeta(s)-1` 값을 계산합니다. 
    위 함수와 마찬가지로 :math:`s \neq 1` 이어야 합니다.

후르비츠(Hurwitz) 제타 함수 (Hurwitz Zeta Function)
---------------------------------------------------------

후르비츠 제타함수는 다음과 같이 정의됩니다.

.. math:: 
    
    \zeta(s,q) = \sum_0^\infty (k+q)^{-s}

.. c:function:: double gsl_sf_hzeta (double s, double q)
                int gsl_sf_hzeta_e (double s, double q, gsl_sf_result * result)


    후르비츠 제타 함수 :math:`\zeta (s,q)`  의 값을 계산합니다. 
    :math:`s>1, q>0` 이어야 합니다.

에타(Eta) 함수 (Eta Function)
-----------------------------------------

에타 함수는 다음과 같이 정의됩니다.

.. math:: 
    
    \eta(s) = (1-2^{1-s}) \zeta(s)


.. c:function:: double gsl_sf_eta_int (int n)
                int gsl_sf_eta_int_e (int n, gsl_sf_result * result)

    정수 :math:`n` 대해 에타 함수 :math:`\eta(n)` 의 값을 계산합니다.

.. c:function:: double gsl_sf_eta (double s)
                int gsl_sf_eta_e (double s, gsl_sf_result * result)


    임의의 수 :math:`s` 대해 에타 함수 :math:`\eta(s)` 의 값을 계산합니다.
