.. index::
   single: Jacobi elliptic functions
   single: elliptic functions (Jacobi)
   single: 란덴 변환
   single: Landen transform


자코비 타원 함수들은 Abramowitz & Stegun, 16 단원의 정의를 따릅니다. 
이 함수들은 :code:`gsl_sf_elljac.h` 에 정의되어 있습니다.


.. c:function:: int gsl_sf_elljac_e (double u, double m, double * sn, double * cn, double * dn)

    자코비 타원 함수 :math:`sn(u\|m), cn(u\|m) , dn(u\|m)` 을 내림차순 란덴 변환을 이용해 계산합니다.
