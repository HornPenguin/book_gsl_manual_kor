.. index:: elliptic integrals

이 단원에서 기술된 함수들은 헤더 파일 :code:`gsl_sf_ellint.h`  에 정의되어 있습니다. 
타원 적분에 관한 더 자세한 정보들은 Abramowitz & Stegun, Chpater 17를 참고해 볼 수 있습니다.

르장드르 형태 정의 (Definition of Legendre Forms)
----------------------------------------------------------------

타원 적분의 르장드르 형태 :math:`F(\phi, k), E(\phi, k)` 그리고 :math:`\Pi(\phi, k, n)` 는 
다음과 같이 정의됩니다.

.. math::

    F(\phi,k) = \int_0^{\phi} dt \frac{1}{\sqrt(1- k^2 \sin^2 (t))}\\
    E(\phi,k) = \int_0^{\phi} dt {\sqrt(1- k^2 \sin^2 (t))}\\
    \Pi(\phi, k, n) = \int_0^{\phi} dt \frac{1}{(1+n \sin^2(t)) \sqrt{1-k^2 \sin^2 (t)}}

르장드르 형태의 완전 타원 적분은 :math:`K(k) = F(\pi/2, k)` 와 :math:`E(k) = E(\pi/2, k)` 로 표기할 수 있습니다.

이 단원에서 사용하는 표기법은 Carlson, "Numerische Mathematik" 33 (1979) 1 에 기반해 있습니다. 
이 표기는 Abramowitz & Stegun의 표기와 조금 다른데, 함수의 표기에서 인자가 :math:`m=k^2` 이고, :math:`n` 이 :math:`-n` 으로 바뀌어 있습니다.

칼슨 형태 정의 (Definition of Carlson Forms)
----------------------------------------------

킬슨 대칭 형태 함수 :math:`RC(x,y), RD(x,y,z), RF(x,y,z)` 와  
:math:`RJ(x,y,z,p)` 는 다음과 같이 정의됩니다.

.. math::

    RC(x,y)   &= 1/2 \int_0^\infty dt (t+x)^{-1/2} (t+y)^{-1} \\
    RD(x,y,z) &= 3/2 \int_0^\infty dt (t+x)^{-1/2} (t+y)^{-1/2} (t+z)^{-3/2} \\
    RF(x,y,z) &= 1/2 \int_0^\infty dt (t+x)^{-1/2} (t+y)^{-1/2} (t+z)^{-1/2} \\
    RJ(x,y,z,p) &= 3/2 \int_0^\infty dt (t+x)^{-1/2} (t+y)^{-1/2} (t+z)^{-1/2} (t+p)^{-1}

르장드르 형태-완전 타원 적분 (Legendre Form of Complete Elliptic Integrals)
----------------------------------------------------------------------------

.. c:function:: double gsl_sf_ellint_Kcomp (double k, gsl_mode_t mode)
              int gsl_sf_ellint_Kcomp_e (double k, gsl_mode_t mode, gsl_sf_result * result)

    완전 타원 적분의 르장드르 형태 :math:`K(k)` 를 :math:`mode` 변수의 값에 따라 
    정확도를 결정해 계산합니다. Abramowitz & Stegun에서 이 함수는 :math:`m=k^2` 이라는 점에 
    유의해야 합니다.

.. c:function:: double gsl_sf_ellint_Ecomp (double k, gsl_mode_t mode)
              int gsl_sf_ellint_Ecomp_e (double k, gsl_mode_t mode, gsl_sf_result * result)

    완전 타원 적분의 르장드르 형태 :math:`E(k)` 를 :math:`mode` 변수의 값에 따라 정확도를 결정해 계산합니다. 
    Abramowitz & Stegun에서 이 함수는 :math:`m=k^2` 이라는 점에 유의해야 합니다.

.. c:function:: double gsl_sf_ellint_Pcomp (double k, double n, gsl_mode_t mode)
              int gsl_sf_ellint_Pcomp_e (double k, double n,  gsl_mode_t mode, gsl_sf_result * result)

    완전 타원 적분의 르장드르 형태 :math:`\Pi(k, n)` 를 :math:`mode`  변수의 값에 따라 정확도를 결정해 계산합니다. 
    Abramowitz & Stegun에서 이 함수는 :math:`m=k^2` 이고 :math:`\sin^2(\alpha) = k^2` 이고, :math:`n` 의 부호를 :math:`-n` 으로 바뀌었다는 점에 유의해야 합니다.


르장드르 형태-불완전 타원 적분 (Legendre Form of Incomplete Elliptic Integrals)
-----------------------------------------------------------------------------------

.. c:function:: double gsl_sf_ellint_F (double phi, double k, gsl_mode_t mode)
              int gsl_sf_ellint_F_e (double phi, double k, gsl_mode_t mode, gsl_sf_result * result)

    타원 적분의 르장드르 형태 :math:`K(\phi, k)` 를 :math:`mode` 변수의 값에 따라 정확도를 결정해 계산합니다. 
    Abramowitz & Stegun에서 이 함수는 :math:`m=k^2`  이라는 점에 유의해야 합니다.

.. c:function:: double gsl_sf_ellint_E (double phi, double k, gsl_mode_t mode)
              int gsl_sf_ellint_E_e (double phi, double k, gsl_mode_t mode, gsl_sf_result * result)

    완전 타원 적분의 르장드르 형태 :math:`E(\phi, k)` 를 :math:`mode`  변수의 값에 따라 정확도를 결정해 계산합니다. 
    Abramowitz & Stegun에서 이 함수는 :math:`m=k^2` 이라는 점에 유의해야 합니다.

.. c:function:: double gsl_sf_ellint_P (double phi, double k, double n, gsl_mode_t mode)
              int gsl_sf_ellint_P_e (double phi, double k, double n, gsl_mode_t mode, gsl_sf_result * result)

    완전 타원 적분의 르장드르 형태 :math:`\Pi(\phi, k, n)` 를 :math:`mode` 변수의 값에 따라 정확도를 결정해 계산합니다. 
    Abramowitz & Stegun에서 이 함수는 :math:`m=k^2`  이고 :math:`\sin^2(\alpha) = k^2` 이고, :math:`n` 의 부호를 :math:`-n` 으로 바뀌었다는 점에 유의해야 합니다.

.. c:function:: double gsl_sf_ellint_D (double phi, double k, gsl_mode_t mode)
              int gsl_sf_ellint_D_e (double phi, double k, gsl_mode_t mode, gsl_sf_result * result)

    타원 적분 :math:`D(\phi, k)` 을 계산합니다. 이 함수는 칼슨 형태 타원 함수 :math:` RD(x,y,z)` 와 다음의 관계로 정의되어 있습니다.

    .. math::
    
        D(\phi, k) = \frac{1}{3}(\sin \phi)^3 RD(1-\sin^2(\phi), 1-k^2\sin^2(\phi),1)

칼슨 형태 (Carlson Forms)
-------------------------

.. c:function:: double gsl_sf_ellint_RC (double x, double y, gsl_mode_t mode)
              int gsl_sf_ellint_RC_e (double x, double y, gsl_mode_t mode, gsl_sf_result * result)

    타원적분 :math:`RC(x, y)` 를 :math:`mode` 변수의 값에 따라 정확도를 결정해 계산합니다.

.. c:function:: double gsl_sf_ellint_RD (double x, double y, double z, gsl_mode_t mode)
              int gsl_sf_ellint_RD_e (double x, double y, double z, gsl_mode_t mode, gsl_sf_result * result)

    타원적분 :math:`RD(x ,y, z)` 를 :math:`mode` 변수의 값에 따라 정확도를 결정해 계산합니다.

.. c:function:: double gsl_sf_ellint_RF (double x, double y, double z, gsl_mode_t mode)
              int gsl_sf_ellint_RF_e (double x, double y, double z, gsl_mode_t mode, gsl_sf_result * result)

    타원적분 :math:`RF(x, y, z)` 를 :math:`mode` 변수의 값에 따라 정확도를 결정해 계산합니다.

.. c:function:: double gsl_sf_ellint_RJ (double x, double y, double z, double p, gsl_mode_t mode)
              int gsl_sf_ellint_RJ_e (double x, double y, double z, double p, gsl_mode_t mode, gsl_sf_result * result)

    타원적분 :math:`RJ(x, y, z, p)` 를 :math:`mode` 변수의 값에 따라 정확도를 결정해 계산합니다.


