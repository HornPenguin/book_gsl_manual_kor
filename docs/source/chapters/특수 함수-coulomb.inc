.. index::
   single: Coulomb wave functions
   single: hydrogen atom

쿨롱 함수의 초안은 헤더 파일 :code:`gsl_sf_coulomb.h`  에 정의되어 있습니다. 
구속 상태와 산란해를 모두 포함합니다.

정규화 된 수소의 구속 상태
--------------------------------------------------------------------

.. c:function:: double gsl_sf_hydrogenicR_1 (double Z, double r)
                int gsl_sf_hydrogenicR_1_e (double Z, double r, gsl_sf_result * result)

    가장 낮은 차수의 정규화 된 수소의 구속 방사형 상태  함수 :math:`R_1 = 2 Z \sqrt{Z} \exp (-Zr)`  를 계산합니다.

.. c:function:: double gsl_sf_hydrogenicR (int n, int l, double Z, double r)
                int gsl_sf_hydrogenicR_e (int n, int l, double Z, double r, gsl_sf_result * result)

    :math:`n`  차수의 정규화 된 수소의 구속 방사형 상태 함수 

    .. math::
 
        R_n := \frac{2 Z^{3/2}}{n^2} (\frac{2Zr}{n})^l \sqrt{\frac{(n-l-1)!}{n+l}} \exp(-Zr /n) L_{n-l-1}^{2l+1} (2Zr/n)

    를 계산합니다. :math:`L_b^a(x)` 는 일반화 된 르장드르 다항식입니다. 
    이 정규화 방법은 수소의 파동 함수 :math:`\psi` 가 :math:`\psi(n,l,r) = R_n Y_{lm}` 로 주어지도록 정해졌습니다.

쿨롱 파동 함수
----------------------------------------

쿨롱 파동함수 :math:`F_L(\eta,x), G_L (\eta,x)`  들은 Abramowitz & Stegun Chapter 14에 기술되어 있습니다. 
다양하고 넓은 범위의 값들을 가지기 때문에, 오버플로우를 이용할 수 있도록 구현되었습니다. 
만약, 오버플로우가 발생한다면, :code:`GSL_EOVERFLW` 값을 반환하고 :code:`exponent(s)` 는 
수정 가능한 인자 :code:`exp_F` 와 :code:`exp_G` 를 반환합니다. 
완전해는 다음과 같이 구할 수 있습니다.

.. math:: 
 
    F_L(\eta,x) = f_c[k_L] * \exp(exp_F) \\
    G_L(\eta,x) = g_c[k_L] * \exp(exp_G)

.. math:: 
    
    {F'}_L(\eta,x)= f_{cp}[k_L] * \exp(exp_F)\\
    {G'}_L(\eta,x)= g_{cp}[k_L] * \exp(exp_G)

.. c:function:: int gsl_sf_coulomb_wave_FG_e (double eta, double x, double L_F, int k, gsl_sf_result * F, gsl_sf_result * Fp, gsl_sf_result * G, gsl_sf_result * Gp, double * exp_F, double * exp_G)

    이 함수는 쿨롱 파동 함수 :math:`F_L(\eta,x), G_{L-k}(\eta,x)` 와 그 도함수  
    :math:`F'_L(\eta,x), G'_{L-k}(\eta,x)` 를 인자 :code:`x`에 대해 계산합니다. 
    각 계수들은 :math:`L` 에 대해 다음의 제약조건을 가집니다.  

    .. math:: 

        L-k > -1/2, x>0, k \in \mathbb{Z}
    
    유의할 점은 :math:`L` 이 반드시 정수로 있을 필요는 없다는 점입니다. 
    결과 값들은 인자 :code:`F` 와 :code:`G` 에 함수 값이 저장되고, 도함수의 값은 :code:`Fp` 와 :code:`Gp` 에 저장됩니다. 
    오버플로우가 발생하면, :code:`GSL_EOVERFLW`  가 반환되고 조정된 지수값이 수정 가능한 인자 :code:`exp_F` 와 :code:`exp_G` 에 저장됩니다.

.. c:function:: int gsl_sf_coulomb_wave_F_array (double L_min, int kmax, double eta, double x, double fc_array[], double * F_exponent)

    이 함수는 :math:`L = L_{min} \dots L_{min} + k_{max}` 에 대해, 
    함수 :math:`F_L(\eta,x)` 의 값을 계산합니다.
    계산 결과값은 :code:`fc_array`  배열에 저장됩니다. 
    오버플로우가 발생하면 지수값이 :code:`F_exponenet` 에 저장됩니다.

.. c:function:: int gsl_sf_coulomb_wave_FG_array (double L_min, int kmax, double eta, double x, double fc_array[], double gc_array[], double * F_exponent, double * G_exponent)

    이 함수는 :math:`L = L_{min} \dots L_{min} + k_{max}`  에 대해, 
    함수 :math:`F_L(\eta,x), G_L(\eta,x)` 의 값을 계산합니다.  
    계산 결과값은 각각 :code:`fc_array` 와 :code:`gc_array` 배열에 저장됩니다. 
    오버플로우가 발생하면 지수값이 :code:`F_exponenet` 와 :code:`G_exponent` 에 저장됩니다.


.. c:function:: int gsl_sf_coulomb_wave_FGp_array (double L_min, int kmax, double eta, double x, double fc_array[], double fcp_array[], double gc_array[], double gcp_array[], double * F_exponent, double * G_exponent)

    이 함수는 :math:`L = L_{min} \dots L_{min} + k_{max}` 에 대해, 
    함수 :math:`F_L(\eta,x), G_L(\eta,x)` 와 그 도함수  
    :math:`F'_L(\eta,x), G'_L(\eta,x)` 의 값을 계산합니다.  
    계산 결과값은 각각 :code:`fc_array` , :code:`gc_array` , :code:`fcp_array` 그리고 :code:`gcp_array` 배열에 저장됩니다.
    오버플로우가 발생하면 지수값이 :code:`F_exponenet` 와 :code:`G_exponent` 에 저장됩니다.

.. c:function:: int gsl_sf_coulomb_wave_sphF_array (double L_min, int kmax, double eta, double x, double fc_array[], double F_exponent[])

    이 함수는 :math:`L = L_{min} \dots L_{min} + k_{max}` 에 대해, 
    인자로 나누어진 쿨롱 함수 :math:`F_L(\eta,x)/x` 값을 계산합니다.  
    계산 결과값은 :code:`fc_array`  배열에 저장됩니다. 
    오버플로우가 발생하면 지수값이 :code:`F_exponenet` 에 저장됩니다.  
    :math:`\eta \rightarrow 0` 이 함수는 구면 베셀 함수로 수렴합니다.

쿨롱 파동함수의 정규화 계수
-----------------------------------------------------------------------------

쿨롱 파동 함수의 정규화 상수들은 Abramowitz 14.1.7에 정의되어 있습니다.

.. c:function:: int gsl_sf_coulomb_CL_e (double L, double eta, gsl_sf_result * result)

   :math:`L>-1` 에 대해, 쿨롱 파동 함수의 정규화 계수 :math:`C_L (\eta)` 를 계산합니다.

.. c:function:: int gsl_sf_coulomb_CL_array (double Lmin, int kmax, double eta, double cl[])

   :math:`L = L_{min} \dots L_{min} + k_{max}, L_{min} > -1`  에 대해, 쿨롱 파동 함수의 정규화 계수 :math:`C_L(\eta)` 를 계산합니다.
