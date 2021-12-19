
르장드르 다항식과 함수들은 Abramowitz & Stegun Chapter 8. 에 기술되어있습니다. 
    :code:`gsl_sf_legnedre.h`  헤더 파일에 정의되어 있습니다.

르장드르 다항식(Legendre Polynomials)
------------------------------------------

.. function:: double gsl_sf_legendre_P1 (double x)
              double gsl_sf_legendre_P2 (double x)
              double gsl_sf_legendre_P3 (double x)
              int gsl_sf_legendre_P1_e (double x, gsl_sf_result * result)
              int gsl_sf_legendre_P2_e (double x, gsl_sf_result * result)
              int gsl_sf_legendre_P3_e (double x, gsl_sf_result * result)

    르장드르 다항식 :math:`P_l (x)` 을 :math:`l= 1, 2, 3` 에 대해 계산합니다. 
    이 계산은 해당 함수들의 수학적 정의식을 사용합니다.

.. function:: double gsl_sf_legendre_Pl (int l, double x)
              int gsl_sf_legendre_Pl_e (int l, double x, gsl_sf_result * result)

    르장드르 다항식 :math:`P_l(x)` 을 주어진 :math:`l` 과 :math:`x` 에 대해 계산합니다. 
    이때, :math:`l` 과 :math:`x` 는 :math:`l \geq 0` 과 :math:`|x| \leq 1` 을 만족해야 합니다.


.. function:: int gsl_sf_legendre_Pl_array (int lmax, double x, double result_array[])
              int gsl_sf_legendre_Pl_deriv_array (int lmax, double x, double result_array[], double result_deriv_array[])

    :math:`l= 0, \dots lmax` 와 :math:`|x| \leq 1` 에 대해, 
    르장드르 다항식 :math:`P_l(x)` 과 그 도함수 :math:`dP_l (x)/dx` 를 
    주어진 배열 :math:`result_array[]` 에 계산합니다.

.. function:: double gsl_sf_legendre_Q0 (double x)
              int gsl_sf_legendre_Q0_e (double x, gsl_sf_result * result)

    :math:`x>-1` 과 :math:`x \neq 1` 에 대해, 르장드르 함수 :math:`Q_0(x)` 를 계산합니다.

.. function:: double gsl_sf_legendre_Q1 (double x)
              int gsl_sf_legendre_Q1_e (double x, gsl_sf_result * result)

    :math:`x>-1` 과 :math:`x \neq 1` 에 대해, 르장드르 함수 :math:`Q_1(x)` 를 계산합니다.

.. function:: double gsl_sf_legendre_Ql (int l, double x)
              int gsl_sf_legendre_Ql_e (int l, double x, gsl_sf_result * result)

  :math:`x>-1` , :math:`x \neq 1` 과 :math:`l \geq 0` 에 대해 ,르장드르 함수 :math:`Q_l(x)` 를 계산합니다.

버금 르장드르 함수와 구면 조화 함수 (Associated Legendre Polynomials and Spherical Harmonics)
-------------------------------------------------------------------------------------------------------------

이 단원의 함수들은 버금 르장드르 함수 :math:`P_l^m(x)` 의 값을 계산합니다. 
    다음 미분 방정식의 해입니다.

.. math::

    (1-x^2) \frac{d^2}{d x^2}P_l^m(x) -2x \frac{d}{dx}P_l^m(x) + (l(l+1) - \frac{m^2}{1-x^2})P_l^m(x) =0

:math:`l` 과 :math:`m` 은 :math:`0 \leq l` 과 :math:`0 \leq m \leq l` 을 만족합니다. 
함수 :math:`P_l^m(x)` 는 조합적으로 상승하며 :math:`l` 이 :math:`150` 보다 클 경우 오버플로우가 발생합니다. 
이를 대신해서 정규화 된 버금 르장드르 함수를 계산할 수 있습니다. 
다양한 종류의 정규화 표현이 존재하고, degree와 order가 :math:`2700` 인 함수까지 안정적으로 계산할 수 있습니다. 
이 라이브러리에서는 다음의 정규화 표현을 제공합니다.

* 슈미트 반 정규화 (Schmidt semi-normalization)

  슈미트 반 정규화 버금 르장드르 함수는 자기 교환 계산에 빈번히 사용됩니다. 이는 다음과 같이 계산할 수 있습니다.

  .. math::

    S_l^0 (x) = P_l^0 (x)\\
    S_l^m (x) = (-1)^m \sqrt{2 \frac{(l-m)!}{(l+m)!}}P_l^m (x), m > 0

  계수 :math:`(-1)^m`  은 Condon-Shortley 위상 계수로 불리며, 
  필요시 함수에서 :math:`csphase =1` 인자를 설정해 무시할 수 있습니다.

* 구면 조화 정규화 (Spherical Harmonic Normalization)

  버금 르장드르 함수는 다음과 같이 구면 조화 함수를 계산하는 데 쓸 수 있습니다.

  .. math::

     Y_l^m(x) = (-1)^m \sqrt{\frac{2l+1}{4 \pi}\frac{(l-m)!}{(l+m)!}} P_l^m(x)

  계수 :math:`(-1)^m` 은 필요시 계산에서 제외할 수 있습니다. 
   

* 완전 정규화 (Full Normalization)
  
  완전 정규화된 버금 르장드르 다항식은 다음과 같이 정의됩니다.

  .. math::

      N_l^m(x) = (-1)^m \sqrt{(1+ \frac{1}{2}\frac{(l-m)!}{(l+m)!}}P_l^m(x)
   
  이 때, 다음과 같은 성질을 가집니다.

  .. math::

      \int_{-1}^1 N_l^m(x) \, dx = 1

아래에 나올 정규화된 버금 르장드르 함수를 계산하는 함수들은 재귀적 방법을 사용합니다. 
이 방법은 degree :math:`l` 과 order :math:`m` 이 2700 이하라면, 안정적으로 계산할 수 있습니다. 
이 값을 넘어서면 계산 함수들은 언더플로우를 일으켜 부정확한 값을 반환합니다. 
각 함수들은 :math:`1` -계 도함수 :math:`dP_l^m(x)/dx`  와 :math:`2` -계 도함수 :math:`d^2 P_l^m(x)/ dx^2`  을 
제공하며, 이와 함께 :math:`dP_l^m(\cos\theta) / d \theta` 와 :math:`d^2 P_l^m(\cos\theta)/d\theta^2` 도 같이 제공합니다. 
이 두 종류의 도함수들은 단순한 비례 관계를 가집니다. 
:math:`\theta` 에 관한 미분은 구면 조화 함수에서 매우 빈번히 사용되기 때문에 
이 기능 또한 같이 제공하고 있습니다.

아래의 함수에서 :math:`gsl_sf_legendre_t`  인자를 이용해 정규화 방법을 선택할 수 있습니다. 
가능한 값들은 다음과 같습니다.

.. type:: gsl_sf_legendre_t
    

   ================================== ===============================================================================
   값                                 설명
   ================================== ===============================================================================
   :code:`GSL_SF_LEGENDRE_NONE`       비 정규화된 버금 르장드르 다항식 :math:`P_l^m(x)`
   :code:`GSL_SF_LEGENDRE_SCHMIDT`    슈미트 반 정규화된 버금 르장드르 다항식 :math:`S_l^m(x)`
   :code:`GSL_SF_LEGENDRE_SPHARM`     구면 조화 버금 르장드르 다항식 :math:`Y_l^m(x)`
   :code:`GSL_SF_LEGENDRE_FULL`       완전 정규화 버금 르장드르 다항식 :math:`N_l^m(x)`
   ================================== ===============================================================================



.. function:: int gsl_sf_legendre_array (const gsl_sf_legendre_t norm, const size_t lmax, const double x, double result_array[])
              int gsl_sf_legendre_array_e (const gsl_sf_legendre_t norm, const size_t lmax, const double x, const double csphase, double result_array[])

    정규화된 버금 르장드르 다항식들을, :math:`0 \leq l \leq lmax` , :math:`0 \geq m \geq l` 그리고 :math:`|x| \leq 1` 에 대해 계산합니다. 
    :math:`norm`  인자는 어느 정규화 방법을 사용할지 결정합니다. 
    정규화된 :math:`P_l^m(x)` 값들은 :math:`result_array` 에 저장됩니다. 
    이 값은 :math:`gsl_sf_lengendre_array_n()` 를 호출해 최소 크기를 결정할 수 있습니다.

    배열 :math:`P_l^m(x)` 의 지수는 :math:`gsl_sf_legendre_array_index(l, m)` 를 호출해 얻을 수 있습니다. 
    :math:`_e` 붇은 함수에서 Condon-Shortly 위상 계수 :math:`(-1)^m` 의 포함 유무를 조정하려면 
    :math:`csphase` 을 :math:`-1` 이나 :math:`1` 로 설정해 주면 됩니다. 
    이 계수는 기본적으로 비활성화 되어 있습니다.

.. function:: int gsl_sf_legendre_deriv_array (const gsl_sf_legendre_t norm, const size_t lmax, const double x, double result_array[], double result_deriv_array[])
              int gsl_sf_legendre_deriv_array_e (const gsl_sf_legendre_t norm, const size_t lmax, const double x, const double csphase, double result_array[], double result_deriv_array[])

    :math:`|x| \leq 1` 값에 대해, 정규화된 버금 르장드르 함수들의 :math:`1` 차에서 :math:`lmax` 차 까지의 도함수 값을 계산합니다. 
    :math:`norm` 인자는 어느 정규화 방법을 사용할지 결정합니다. 
    르장드르 함수 :math:`P_l^m(x)` 와 :math:`d P_l^m(x)/ dx` 값은 각각 :math:`result_array` 와 :math:`result_deriv_array` 에 저장됩니다. 
    :math:`_e` 붇은 함수에서 Condon-Shortly 위상 계수 :math:`(-1)^m` 의 포함 유무를 조정하려면 
    :math:`csphase` 을 :math:`-1` 이나 :math:`1` 로 설정해 주면 됩니다. 
    이 계수는 기본적으로 비활성화 되어 있습니다.

.. function:: int gsl_sf_legendre_deriv_alt_array (const gsl_sf_legendre_t norm, const size_t lmax, const double x, double result_array[], double result_deriv_array[])
              int gsl_sf_legendre_deriv_alt_array_e (const gsl_sf_legendre_t norm, const size_t lmax, const double x, const double csphase, double result_array[], double result_deriv_array[])

    :math:`|x| \leq 1` 값에 대해, :math:`1` 차에서 :math:`lmax` 까지의 정규화된 버금 르장드르 함수의 값과 대체된 도함수 값을 계산합니다. 
    르장드르 함수 :math:`P_l^m(x)` 와 :math:`d P_l^m(\cos(\theta))/ d\theta` 의 값들은 
    각각 :math:`result_array` 와 :math:`result_deriv_array` 에 저장됩니다. 
    :math:`_e` 붇은 함수에서 Condon-Shortly 위상 계수 :math:`(-1)^m` 의 포함 유무를 조정하려면 
    :math:`csphase` 을 :math:`-1` 이나 :math:`1` 로 설정해 주면 됩니다. 
    이 계수는 기본적으로 비활성화 되어 있습니다.

.. function:: int gsl_sf_legendre_deriv2_array (const gsl_sf_legendre_t norm, const size_t lmax, const double x, double result_array[], double result_deriv_array[], double result_deriv2_array[])
              int gsl_sf_legendre_deriv2_array_e (const gsl_sf_legendre_t norm, const size_t lmax, const double x, const double csphase, double result_array[], double result_deriv_array[], double result_deriv2_array[])

    :math:`|x| \leq 1` 값에 대해, :math:`1` 차에서 :math:`lmax` 까지의 정규화된 버금 르장드르 함수들, 그 도함수들과 :math:`2` 계 도함수 값들을 계산합니다. 
    :math:`norm` 인자는 어느 정규화 방법을 사용할지 결정합니다. 르장드르 함수 :math:`P_l^m(x)` 와 :math:`d P_l^m(x)/ dx` , 그리고 :math:`2` 계 도함수 :math:`d^2 P_l^m(x) / dx^2` 의 값은 
    각각 :math:`result_array` , :math:`result_deriv_array` , 그리고 :math:`result_deriv2_array` 에 저장됩니다. 
    :math:`_e` 붇은 함수에서 Condon-Shortly 위상 계수 :math:`(-1)^m` 의 포함 유무를 조정하려면 
    :math:`csphase` 을 :math:`-1` 이나 :math:`1` 로 설정해 주면 됩니다. 
    이 계수는 기본적으로 비활성화 되어 있습니다.


.. function:: int gsl_sf_legendre_deriv2_alt_array (const gsl_sf_legendre_t norm, const size_t lmax, const double x, double result_array[], double result_deriv_array[], double result_deriv2_array[])
              int gsl_sf_legendre_deriv2_alt_array_e (const gsl_sf_legendre_t norm, const size_t lmax, const double x, const double csphase, double result_array[], double result_deriv_array[], double result_deriv2_array[])

    :math:`|x| \leq 1`  값에 대해, :math:`1` 차에서 :math:`lmax` 까지의 정규화된 버금 르장드르 함수들, 
    그 대체 도함수들과 :math:`2` 계 도함수 값들을 계산합니다. :math:`norm` 인자는 어느 정규화 방법을 사용할지 결정합니다. 
    르장드르 함수 :math:`P_l^m(x)` 와 :math:`d P_l^m(\cos(\theta))/ d\theta` , 그리고 :math:`2` 계 도함수 
    :math:`d^2 P_l^m(\cos(\theta)) / d\theta^2` 의 값은 각각 :math:`result_array` , :math:`result_deriv_array`, 
    그리고 :math:`result_deriv2_array` 에 저장됩니다. 
    :math:`_e` 붇은 함수에서 Condon-Shortly 위상 계수 :math:`(-1)^m` 의 포함 유무를 조정하려면 
    :math:`csphase` 을 :math:`-1` 이나 :math:`1` 로 설정해 주면 됩니다. 
    이 계수는 기본적으로 비활성화 되어 있습니다.

.. function:: size_t gsl_sf_legendre_nlm(const size_t lmax)

    :math:`lmax` 까지의 버금 르장드르 함수 :math:`P_l^m(x)` 의 갯수를 반환합니다. 
    해당 값은 :math:`(lmax_1)* (lmax+2)/2` 입니다.

.. function:: size_t gsl_sf_legendre_array_n (const size_t lmax)

    최대 차수 :math:`lmax` 까지의 배열 버전 버금 르장드르 함수에 필요한 최소 배열의 크기를 반환합니다. 
    이 값은 :math:`P_l^m(x)` 의 최댓값과 재귀식을 계산할 때 필요한, 곱 계수 계산을 위한 공간을 더한 값입니다.

.. function:: size_t gsl_sf_legendre_array_index (const size_t l, const size_t m)

    :math:`result_array` :math:`result_deriv_array` 그리고 :math:`result_deriv2_array` 배열의 색인 값을 반환합니다. 
    해당 값은 :math:`P_l^m(x)` , :math:`P'_l^m(x)` , 그리고 :math:`P''_l^m(x)` 에 대응되고 
    주어진 :math:`l` :math:`m` 대해, :math:`l(l_1)//2 +m`  으로 정해집니다.

 :math:`HAVE_INLINE`  사용하면 인라인 버전의 함수를 사용할 수 있습니다.

.. function:: double gsl_sf_legendre_Plm (int l, int m, double x)
              int gsl_sf_legendre_Plm_e (int l, int m, double x, gsl_sf_result * result)

    :math:`m \geq 0, l \geq m` 그리고 :math:`|x| \leq 1` 에 대해, 
    버금 르장드르 함수 :math:`P_l^m(x)` 의 값을 계산합니다.


.. function:: double gsl_sf_legendre_sphPlm (int l, int m, double x)
              int gsl_sf_legendre_sphPlm_e (int l, int m, double x, gsl_sf_result * result)

    구면 조화 함수에서 사용하기 위한, 정규회된 버금 르장드르 다항식 
    :math:`\sqrt{(2l+1)/(4\pi)} \sqrt{(l-m)! / (l+m)!} P_l^m(x)` 값을 계산합니다. 
    앞의 계수는 :math:`m \geq 0, l \geq m` 그리고 :math:`|x| \leq 1` 를 만족해야합니다.
    표준 정규화과정에서 일어나는 오버플로우를 피할 수 있습니다.

.. function:: int gsl_sf_legendre_Plm_array (int lmax, int m, double x, double result_array[])
              int gsl_sf_legendre_Plm_deriv_array (int lmax, int m, double x, double result_array[], double result_deriv_array[])

    현재 비활성화 되어 있고 차후 버전에서 삭제될 예정입니다. 
    :math:`gsl_sf_legendre_array()` 와 :math:`gsl_sf_legendre_deriv_array()` 를 참고하길 바랍니다.


.. function:: int gsl_sf_legendre_sphPlm_array (int lmax, int m, double x, double result_array[])
              int gsl_sf_legendre_sphPlm_deriv_array (int lmax, int m, double x, double result_array[], double result_deriv_array[])

    현재 비활성화 되어 있고 차후 버전에서 삭제될 예정입니다. 
    :math:`gsl_sf_legendre_array()` 와 :math:`gsl_sf_legendre_deriv_array()` 를 참고하길 바랍니다.

.. function:: int gsl_sf_legendre_array_size (const int lmax, const int m)

  현재 비활성화 되어 있고 차후 버전에서 삭제될 예정입니다.

원뿔 함수 (Conial Functions)
----------------------------------

원통 함수 :math:`P_{-(1/2)+i\lambda}^\mu` 와 :math:`Q^{\mu}_{-(1/2)+i\lambda}` 는 
Abramowitz & Stegun 8.12 단원에 기술되어 있습니다.

.. function:: double gsl_sf_conicalP_half (double lambda, double x)
              int gsl_sf_conicalP_half_e (double lambda, double x, gsl_sf_result * result)

    :math:`x>-1` 에 대해, 비정칙 구면 원뿔 함수 :math:`P_{-1/2+i\lambda}^{1/2} (x)` 값을 계산합니다.

.. function:: double gsl_sf_conicalP_mhalf (double lambda, double x)
              int gsl_sf_conicalP_mhalf_e (double lambda, double x, gsl_sf_result * result)

    :math:`x>-1` 에 대해, 정칙 구면 원뿔 함수 :math:`P_{-1/2+i\lambda}^{1/2} (x)` 값을 계산합니다.


.. function:: double gsl_sf_conicalP_0 (double lambda, double x)
              int gsl_sf_conicalP_0_e (double lambda, double x, gsl_sf_result * result)

    :math:`x>-1` 에 대해, 원뿔 함수 :math:`P_{-1/2+i\lambda}^{0} (x)` 값을 계산합니다.

.. function:: double gsl_sf_conicalP_1 (double lambda, double x)
              int gsl_sf_conicalP_1_e (double lambda, double x, gsl_sf_result * result)

    :math:`x>-1` 에 대해, 원뿔 함수 :math:`P_{-1/2+i\lambda}^{1} (x)` 값을 계산합니다.

.. function:: double gsl_sf_conicalP_sph_reg (int l, double lambda, double x)
              int gsl_sf_conicalP_sph_reg_e (int l, double lambda, double x, gsl_sf_result * result)

    :math:`x>-1` , :math:`l \geq -1` 에 대해, 
    정칙 구면 원뿔 함수 :math:`P_{1/2+i\lambda}^{-1/2-l} (x)` 값을 계산합니다.

.. function:: double gsl_sf_conicalP_cyl_reg (int m, double lambda, double x)
              int gsl_sf_conicalP_cyl_reg_e (int m, double lambda, double x, gsl_sf_result * result)

    :math:`x>-1` , :math:`m \geq -1` 에 대해, 
    정칙 원통 원뿔 함수 :math:`P_{1/2+i\lambda}^{-m} (x)` 값을 계산합니다.


쌍곡 공간에서의 방사 함수 (Radial Functions for Hyperbolic Space)
-------------------------------------------------------------------------------

다음의 구면 함수들은 :math:`3` 차원 쌍곡 공간 :math:`H^3` 속 라플라시안의 고유 함수들인 르장드르 함수들입니다. 
특히 중점으로 다루는 부분은 평평한 극한(flat limit)으로 :math:`\lambda \rightarrow \infty, \eta \rightarrow 0` 이고, 
:math:`\lambda \eta` 가 상수로 고정된 상황입니다.

.. function:: double gsl_sf_legendre_H3d_0 (double lambda, double eta)
              int gsl_sf_legendre_H3d_0_e (double lambda, double eta, gsl_sf_result * result)

    :math:`3` 차원 쌍곡 공간 라플라시안의 :math:`0` 차 고유 함수를 계산합니다.
    다음과 같이 정의되어 있습니다. :math:`\eta \geq 0` 에 대해, 

    .. math::
    
        L_0^{H 3d} (\lambda, \eta) := \frac{\sinn(\lambda \eta)}{\lambda \sinh(\eta)}

    평평한 극한값은 :math:`L_0^{H 3d} (\lambda ,\eta) = j_0(\lambda \eta)` 의 형태를 가집니다.

.. function:: double gsl_sf_legendre_H3d_1 (double lambda, double eta)
              int gsl_sf_legendre_H3d_1_e (double lambda, double eta, gsl_sf_result * result)

    :math:`3` 차원 쌍곡 공간 라플라시안의 :math:`1` 차 고유 함수를 계산합니다.
    다음과 같이 정의되어 있습니다. :math:`\eta \geq 0` 에 대해, 

    .. math::
    
        L_1^{H 3d} (\lambda, \eta) := \frac{1}{\sqrt{\lambda^2 +1}}(\frac{\sinn(\lambda \eta)}{\lambda \sinh(\eta)}) (\coth(\eta) - \lambda \cot(\lambda \eta))

    평평한 극한값은 :math:`L_1^{H 3d} (\lambda ,\eta) = j_1(\lambda \eta)` 의 형태를 가집니다.

.. function:: double gsl_sf_legendre_H3d (int l, double lambda, double eta)
              int gsl_sf_legendre_H3d_e (int l, double lambda, double eta, gsl_sf_result * result)

    :math:`\eta \geq 0, l \geq 0` 에 대해, :math:`l` 차수의 방사 고유 함수값을 계산합니다. 
    이 고유 함수들은 :math:`3` 차원 쌍곡 공간 속 라플라시안의 고유 함수들입니다. 
    평평한 극한값은 :math:`L_l^{H 3d} (\lambda ,\eta) = j_l (\lambda \eta)` 형태를 가집니다.

.. function:: int gsl_sf_legendre_H3d_array (int lmax, double lambda, double eta, double result_array[])

    :math:`0 \leq l \leq lmax` 방사 고유 함수 :math:`L_l^{H 3d} (\lambda, \eta)` 의 값을 계산합니다.

