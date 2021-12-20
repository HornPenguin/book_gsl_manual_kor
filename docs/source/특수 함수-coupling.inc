.. index::
   single: coupling coefficients
   single: 3-j symbols
   single: 6-j symbols
   single: 9-j symbols
   single: Wigner coefficients
   single: Racah coefficients

위그너 :math:`3-j` , :math:`6-j` ,, 그리고  
:math:`9-j`  기호들은, 결합된 각 운동량 벡터들의 상호 작용 계수들을 나타냅니다. 
표준 상호작용 계수 함수들의 인자가 정수거나 반-정수(half-integer)이기 때문에, 
이를 계산하는 함수들의 인자들도 이와 같습니다. 
이 정수들은 실제 스핀 값들의 두 배를 의미합니다.  
:math:`3-j`  계수들에 대한 더 자세한 정보는 Abramowitz & Stegun, Section 27.9를 참조할 수 있습니다. 
이 단원의 함수들은 헤더 파일 :code:`gsl_sf_coupling.h`  에 기술되어 있습니다.

3-j 기호(3-j Symbols)
-------------------------
.. c:function:: double gsl_sf_coupling_3j (int two_ja, int two_jb, int two_jc, int two_ma, int two_mb, int two_mc)
              int gsl_sf_coupling_3j_e (int two_ja, int two_jb, int two_jc, int two_ma, int two_mb, int two_mc, gsl_sf_result * result)

    위그너 :math:`3-j` 계수

    .. math::

        \begin{pmatrix} 
        ja & jb & jc \\\\
        ma & mb & mc
        \end{pmatrix}

    를 계산합니다. 인자들은 반-정수 값을 가집니다. 
    예를 들어, :math:`ja=`  :math:`two_ja` /2 이고, :math:` ma=` :math:`two_ma` /2 입니다.

6-j 기호(6-j Symbols)
-------------------------
.. c:function:: double gsl_sf_coupling_6j (int two_ja, int two_jb, int two_jc, int two_jd, int two_je, int two_jf)
              int gsl_sf_coupling_6j_e (int two_ja, int two_jb, int two_jc, int two_jd, int two_je, int two_jf, gsl_sf_result * result) 

    위그너 :math:`6-j` 계수

    .. math::

        \begin{Bmatrix} 
        ja & jb & jc \\\\
        jd & je & jf
        \end{Bmatrix}

    를 계산합니다. 인자들은 반-정수 값을 가집니다. 
    예를 들어, :math:`ja=` :math:`two_ja`  /2 이고 :math:`ma=`  :math:`two_ma` /2 입니다.

9-j 기호(9-j Symbols)
-------------------------
.. c:function:: double gsl_sf_coupling_9j (int two_ja, int two_jb, int two_jc, int two_jd, int two_je, int two_jf, int two_jg, int two_jh, int two_ji)
              int gsl_sf_coupling_9j_e (int two_ja, int two_jb, int two_jc, int two_jd, int two_je, int two_jf, int two_jg, int two_jh, int two_ji, gsl_sf_result * result) 

    위그너 :math:`9-j` 계수

    .. math::
        \begin{Bmatrix} 
        ja & jb & jc \\\\
        jd & je & jf \\\\
        jg & jh & ji
        \end{Bmatrix}
    
    를 계산합니다. 
    인자들은 반-정수 값을 값을 가집니다. 
    예를 들어, :math:`ja=`  :math:`two_ja`  /2 이고 :math:`ma=` :math:`two_ma` /2 입니다.
