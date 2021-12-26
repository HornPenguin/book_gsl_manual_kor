.. _BLAS-지원:

************
BLAS 지원
************

기본 선형 대수학 서브 프로그램(Basic Linear Algebra Subprograms; BLAS)에서는 
최적화된 고차원 선형 대수학 기능을 위한 행렬-벡터 연산들을 제공합니다.

이 라이브러리는 C 언어 BLAS 표준(CBLAS라고 합니다)에 해당하는 저수준의 기능들과 
고수준의 GSL 벡터, 행렬들을 위한  기능들을 제공합니다. GSL 벡터와 행렬의 연산을 하고자 한다면, 
여기서 기술하는 고차원 기능들을 사용할 수 있습니다. 
이 단원에서 서술하는 함수들은 :code:`gsl_blas.h`  헤더 파일에 정의되어 있고 
대부분의 사용자들의 요구를 충족시킬 수 있습니다.


알아둘 점은 GSL 행렬들은 밀집 저장(dense-storage)을 사용하여, 
해당하는 BLAS 함수들만이 구현되었다는 점입니다. 
밴드 형식(band-format)이나 팩 형식(packed-format))의 기능을 포함하는 모든 BLAS 기능은 
저 수준의 CBLAS 인터페이스를 통해 사용할 수 있습니다. 
비슷하게 GSL 벡터는 양수 크기의 걸음을 가지지만, 
저 수준의 CBLAS 인터페이스는 BLAS 표준에 정의된 음수 크기의 걸음을 지원합니다. 

BLAS 연산은 3가지로 분류됩니다.

===============  =====================================================
BLAS 연산 단계    설명
===============  =====================================================
**Level 1**           벡터 연산, :math:`y = \alpha x + y`  
**Level 2**           행렬-벡터 연산. :math:`y = \alpha A x + \beta y`  
**Level 3**           행렬-행렬 연산, :math:`C = \alpha A B + C`  
===============  =====================================================

각각의 단계의 함수들은 연산을 분류하는 특별한 이름들을 가지고 있습니다. 
행렬의 형태와 정확도 등을 포함합니다. 가장 흔히 쓰이는 연산들은 아래와 같습니다.


=========  ===============================================
이름        설명
=========  ===============================================
**DOT**     스칼라곱, :math:`x^T y`  
**AXPY**    벡터 함, :math:`\alpha x + y`  
**MV**      행렬-벡터 곱, :math:`Ax`  
**SV**      행렬-벡터 풀이, :math:`A^{-1}x`  
**MM**      행렬-행렬 곱, :math:`AB`  
**SM**      행렬-행렬 풀이, :math:`A^{-1}B`  
=========  ===============================================

행렬의 특성은,

=======  ===============
이름      설명
=======  ===============
**GE**   일반 행렬
**GB**   일반 밴드(band)
**SY**   대칭 행렬
**SB**   대칭 밴드
**SP**   대칭 팩
**HE**   에르미트 행렬
**HB**   에르미트 밴드
**HP**   에르미트 팩
**TR**   삼각 행렬
**TB**   삼각 밴드
**TP**   삼각 팩
=======  ===============



각각의 연산은 4가지 정밀도로 구분됩니다.


======  ===================
이름     설명
======  ===================
**S**    단 정밀도 실수
**D**    배 정밀도 실수
**C**    단 정밀도 복소수
**Z**    배 정밀도 복소수
======  ===================

예를 들어서, :math:`SGEMM` 는 "단 정밀도 실수 일반 행렬-행렬 곱"을 의미하고  
:code:`ZGEMM` 는 "배 정밀도 복소수 일반 행렬-행렬 곱"을 의미합니다.

.. note::

  BLAS 함수들에 인자로 들어가는 벡터와 행렬들은 별칭(alias)된 상태가 아니여야합니다.
  이러한 중첩 상태에 있을 시 결과가 정의되지 않습니다(:ref:`배열-별칭`).

GSL BLAS 인터페이스
========================

GSL은 관련된 자료형에 기반한 밀집 벡터, 행렬 객체들을 제공합니다. 
라이브러리는 이러한 객체들에 적용할 수 있는 BLAS 연산자들에 대한 인터페이스를 제공합니다.
이러한 기능들의 인처페이스들은 :code:`gsl_blas.h` 에 정의되어 있습니다.

Level 1 BLAS 인터페이스
-------------------------

.. c:function:: int gsl_blas_sdsdot (float alpha, const gsl_vector_float * x, const gsl_vector_float * y, float * result)

 :math:`\alpha + x^T y` 값을 주어진 벡터 :math:`x` 와 :math:`y`  대해 계산하고 결과를 :math:`result` 에 반환합니다.

.. c:function:: int gsl_blas_sdot (const gsl_vector_float * x, const gsl_vector_float * y, float * result)
              int gsl_blas_dsdot (const gsl_vector_float * x, const gsl_vector_float * y, double * result)
              int gsl_blas_ddot (const gsl_vector * x, const gsl_vector * y, double * result)

  스칼라 곱 :math:`x^T y` 를 주어진 벡터 :math:`x` 와 :math:`y`  대해 계산하고 결과를 :math:`result` 에 반환합니다.

.. c:function:: int gsl_blas_cdotu (const gsl_vector_complex_float * x, const gsl_vector_complex_float * y, gsl_complex_float * dotu)
              int gsl_blas_zdotu (const gsl_vector_complex * x, const gsl_vector_complex * y, gsl_complex * dotu)

  복소수 스칼라 곱 :math:`x^T y`  를 주어진 벡터 :math:`x` 와 :math:`y`  대해 계산하고 결과를 :math:`result` 에 반환합니다.

.. c:function:: int gsl_blas_cdotc (const gsl_vector_complex_float * x, const gsl_vector_complex_float * y, gsl_complex_float * dotc)
              int gsl_blas_zdotc (const gsl_vector_complex * x, const gsl_vector_complex * y, gsl_complex * dotc)

  켤레 복소 스클라 곱 :math:`x^Hy`  를 주어진 벡터 :math:`x` 와 :math:`y`  대해 계산하고 결과를 :math:`dotc` 에 반환합니다.

.. c:function:: float gsl_blas_snrm2 (const gsl_vector_float * x)
              double gsl_blas_dnrm2 (const gsl_vector * x)

  유클리드 노름 :math:`\|x\|_2 = \sqrt{\sum x_i^2}`  의 값을 주어진 벡터 :math:`x` 에 대해 계산합니다.

.. c:function:: float gsl_blas_scnrm2 (const gsl_vector_complex_float * x)
              double gsl_blas_dznrm2 (const gsl_vector_complex * x)

  유클리드 노름 :math:`\|x\|_2 = \sqrt{\sum \Re(x_i)^2+\Im(x_i)^2}`  의 값을 주어진 복소수 벡터 :math:`x` 에 대해 계산합니다.

.. c:function:: float gsl_blas_sasum (const gsl_vector_float * x)
              double gsl_blas_dasum (const gsl_vector * x)

  절대값 급수 :math:`\sum |x_i|`  의 값을 주어진 벡터 :math:`x` 에 대해 계산합니다.

.. c:function:: float gsl_blas_scasum (const gsl_vector_complex_float * x)
              double gsl_blas_dzasum (const gsl_vector_complex * x)

  실수, 허수의 크기 급수 :math:`\sum (|\Re(x_i)|+|\Im(x_i)|)`  의 값을 주어진 복소수 벡터 :math:`x` 에 대해 계산합니다.


.. c:function:: CBLAS_INDEX_t gsl_blas_isamax (const gsl_vector_float * x)
              CBLAS_INDEX_t gsl_blas_idamax (const gsl_vector * x)
              CBLAS_INDEX_t gsl_blas_icamax (const gsl_vector_complex_float * x)
              CBLAS_INDEX_t gsl_blas_izamax (const gsl_vector_complex * x)

  주어진 벡터 :math:`x` 원소중 가장 큰 원소의 인덱스를 반환합니다. 
  가장 큰 원소는 실수 벡터의 경우 원소의 절대값의 크기가 가장 큰 원소를, 
  복소수 벡터의 경우 실, 허수 부분의 크기의 합 :math:`|\Re(x_i)| + |\Im(x_i)|` 이 가장 큰 원소로 결정됩니다. 
  만약ㅡ 가장 큰 원소가 여러개 있다면, 그 중 첫번째 원소가 반환됩니다.

.. c:function:: int gsl_blas_sswap (gsl_vector_float * x, gsl_vector_float * y)
              int gsl_blas_dswap (gsl_vector * x, gsl_vector * y)
              int gsl_blas_cswap (gsl_vector_complex_float * x, gsl_vector_complex_float * y)
              int gsl_blas_zswap (gsl_vector_complex * x, gsl_vector_complex * y)

  주어진 벡터 :math:`x` 와 :math:`y`  의 원소들을 교환합니다.

.. c:function:: int gsl_blas_scopy (const gsl_vector_float * x, gsl_vector_float * y)
              int gsl_blas_dcopy (const gsl_vector * x, gsl_vector * y)
              int gsl_blas_ccopy (const gsl_vector_complex_float * x, gsl_vector_complex_float * y)
              int gsl_blas_zcopy (const gsl_vector_complex * x, gsl_vector_complex * y)

  주어진 벡터 :math:`x` 원소들을 :math:`y`  로 복사합니다.

.. c:function:: int gsl_blas_saxpy (float alpha, const gsl_vector_float * x, gsl_vector_float * y)
              int gsl_blas_daxpy (double alpha, const gsl_vector * x, gsl_vector * y)
              int gsl_blas_caxpy (const gsl_complex_float alpha, const gsl_vector_complex_float * x, gsl_vector_complex_float * y)
              int gsl_blas_zaxpy (const gsl_complex alpha, const gsl_vector_complex * x, gsl_vector_complex * y)

 :math:`y=\alpha x + y`  의 값을 주어진 벡터 :math:`x` 와 :math:`y`  에 대해 계산합니다.

.. c:function:: void gsl_blas_sscal (float alpha, gsl_vector_float * x)
              void gsl_blas_dscal (double alpha, gsl_vector * x)
              void gsl_blas_cscal (const gsl_complex_float alpha, gsl_vector_complex_float * x)
              void gsl_blas_zscal (const gsl_complex alpha, gsl_vector_complex * x)
              void gsl_blas_csscal (float alpha, gsl_vector_complex_float * x)
              void gsl_blas_zdscal (double alpha, gsl_vector_complex * x)

  벡터 :math:`x` 원소들의 크기를 주어진 값 :math:`alpha` 를 곱해 변경합니다.

.. c:function:: int gsl_blas_srotg (float a[], float b[], float c[], float s[])
              int gsl_blas_drotg (double a[], double b[], double c[], double s[])

  벡터 :math:`(a,b)` 를 0으로 만드는 기븐스(Givens) 회전 :math:`(c,s)` 를 계산합니다.

  .. math::
    \left(
    \begin{matrix}
       c & s \\
      -s & c
    \end{matrix}
    \right)
    \left(
    \begin{matrix}
      a \\
      b
    \end{matrix}
    \right)
    =
    \left(
    \begin{matrix}
      r' \\
      0
    \end{matrix}
    \right)

  변수 :math:`a`  와 :math:`b` 는 명령어에 의해 계산과정에서 여러번 초기화됩니다.

.. c:function:: int gsl_blas_srot (gsl_vector_float * x, gsl_vector_float * y, float c, float s)
              int gsl_blas_drot (gsl_vector * x, gsl_vector * y, const double c, const double s)

  회전 :math:`(x',y') = (cx+sy, -sx+cy)` 을 주어진 벡터 :math:`x` 와 :math:`y` 에 대해 적용합니다.

.. c:function:: int gsl_blas_srotmg (float d1[], float d2[], float b1[], float b2, float P[])
              int gsl_blas_drotmg (double d1[], double d2[], double b1[], double b2, double P[])

  수정 기븐스 변환을 계산합니다. 수정 기븐스 변환은 Level-1 BLAS specification에 정의되어 있습니다.

.. c:function:: int gsl_blas_srotm (gsl_vector_float * x, gsl_vector_float * y, const float P[])
              int gsl_blas_drotm (gsl_vector * x, gsl_vector * y, const double P[])

  수정 기븐슨 변환을 적용합니다.


Level 2 BLAS 인터페이스
-------------------------

.. c:function:: int gsl_blas_sgemv (CBLAS_TRANSPOSE_t TransA, float alpha, const gsl_matrix_float * A, const gsl_vector_float * x, float beta, gsl_vector_float * y)
              int gsl_blas_dgemv (CBLAS_TRANSPOSE_t TransA, double alpha, const gsl_matrix * A, const gsl_vector * x, double beta, gsl_vector * y)
              int gsl_blas_cgemv (CBLAS_TRANSPOSE_t TransA, const gsl_complex_float alpha, const gsl_matrix_complex_float * A, const gsl_vector_complex_float * x, const gsl_complex_float beta, gsl_vector_complex_float * y)
              int gsl_blas_zgemv (CBLAS_TRANSPOSE_t TransA, const gsl_complex alpha, const gsl_matrix_complex * A, const gsl_vector_complex * x, const gsl_complex beta, gsl_vector_complex * y)

  행렬-벡터 사이의 곱, 덧셈인 :math:`y = \alpha op(A) x + \beta y`  을 계산합니다. 
  :code:`op(A) = A, A^T, A.h` 이고 :code:`TransA` = :code:`CblasNoTrans` , :code:`CblasTrans` , :code:`CblasConjTrans` 가 가능합니다.

.. c:function:: int gsl_blas_strmv (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_matrix_float * A, gsl_vector_float * x)
              int gsl_blas_dtrmv (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_matrix * A, gsl_vector * x)
              int gsl_blas_ctrmv (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_matrix_complex_float * A, gsl_vector_complex_float * x)
              int gsl_blas_ztrmv (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_matrix_complex * A, gsl_vector_complex * x)

  행렬-벡터 곱 :math:`x = op(A)x`  를 삼각 행렬 :math:`A` 대해 계산합니다.
  :code:`op(A) = A, A^T, A.h`  이고 :code:`TransA` = :code:`CblasNoTrans` , :code:`CblasTrans` , :code:`CblasConjTrans` 가 가능합니다. 
  :code:`Uplo` 가 :code:`CblasUpper` 일 때, 행렬 :math:`A` 의 상삼각 행렬이 사용되고, 
  :code:`CblasLower` 라면, :math:`A` 의 하삼각 행렬이 사용됩니다. 
  만약, :code:`Dig` 가 :code:`CblasNonUnit` 라면 행렬의 대각 성분들이 사용됩니다.
  :code:`CblasUnit` 라면 행렬 :math:`A` 의 대각 성분들은 유니터리 행렬의 대각성분으로 취급되기 때문에 참고되지 않습니다. 

.. c:function:: int gsl_blas_strsv (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_matrix_float * A, gsl_vector_float * x)
              int gsl_blas_dtrsv (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_matrix * A, gsl_vector * x)
              int gsl_blas_ctrsv (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_matrix_complex_float * A, gsl_vector_complex_float * x)
              int gsl_blas_ztrsv (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_matrix_complex * A, gsl_vector_complex * x)

  주어진 벡터 :math:`x` 대해, :math:`inv(op(A))x`  를 계산합니다.  
  :code:`op(A) = A, A^T, A.h`  이고 :code:`TransA` = :code:`CblasNoTrans` , :code:`CblasTrans` , :code:`CblasConjTrans` 가 가능합니다.
  :code:`Uplo` 가 :code:`CblasUpper`  일 때, 행렬 :math:`A` 의 상삼각 행렬이 사용되고,
  :code:`CblasLower`  라면, 행렬 :math:`A` 의 하삼각 행렬이 사용됩니다. 
  만약, :code:`Dig`가 :code:`CblasNonUnit` 라면 행렬의 대각 성분들이 사용됩니다.
  :code:`CblasUnit` 라면 행렬 :math:`A` 의 대각 성분들은 유니터리 행렬의 대각성분으로 취급되기 때문에 참고되지 않습니다. 

.. c:function:: int gsl_blas_ssymv (CBLAS_UPLO_t Uplo, float alpha, const gsl_matrix_float * A, const gsl_vector_float * x, float beta, gsl_vector_float * y)
              int gsl_blas_dsymv (CBLAS_UPLO_t Uplo, double alpha, const gsl_matrix * A, const gsl_vector * x, double beta, gsl_vector * y)

  행렬-벡터 곱과 합 :math:`y = \alpha Ax + \beta y` 을 대칭 행렬 :math:`A` 에 대해 계산합니다. 
  행렬 :math:`A` 는  대칭 행렬이기 때문에, 상삼각 부분이나 하삼각 부분만 저장해도 됩니다.  
  :code:`Uplo`  가 :code:`CblasUpper`  일 때, 행렬 :math:`A` 의 상삼각 행렬이 사용되고,
  :code:`CblasLower`  라면, 행렬 :math:`A` 의 하삼각 행렬이 사용됩니다. 

.. c:function:: int gsl_blas_chemv (CBLAS_UPLO_t Uplo, const gsl_complex_float alpha, const gsl_matrix_complex_float * A, const gsl_vector_complex_float * x, const gsl_complex_float beta, gsl_vector_complex_float * y)
              int gsl_blas_zhemv (CBLAS_UPLO_t Uplo, const gsl_complex alpha, const gsl_matrix_complex * A, const gsl_vector_complex * x, const gsl_complex beta, gsl_vector_complex * y)

  행렬-벡터 곱과 합 :math:`y = \alpha Ax + \beta y`  을 에르미트 행렬 :math:`A` 에 대해 계산합니다. 
  행렬 :math:`A` 는  대칭 행렬이기 때문에, 상삼각 부분이나 하삼각 부분만 저장해도 됩니다.  
  :code:`Uplo`  가 :code:`CblasUpper`  일 때, 행렬 :math:`A` 의 상삼각 행렬이 사용되고,
  :code:`CblasLower`  라면, 행렬 :math:`A` 의 하삼각 행렬이 사용됩니다. 
  대각 성분의 복소 성분들은 자동적으로 0으로 가정하고 참고되지 않습니다. 


.. c:function:: int gsl_blas_sger (float alpha, const gsl_vector_float * x, const gsl_vector_float * y, gsl_matrix_float * A)
              int gsl_blas_dger (double alpha, const gsl_vector * x, const gsl_vector * y, gsl_matrix * A)
              int gsl_blas_cgeru (const gsl_complex_float alpha, const gsl_vector_complex_float * x, const gsl_vector_complex_float * y, gsl_matrix_complex_float * A)
              int gsl_blas_zgeru (const gsl_complex alpha, const gsl_vector_complex * x, const gsl_vector_complex * y, gsl_matrix_complex * A)

  행렬 :math:`A` 대해, 랭크-1 갱신 :math:`A = \alpha xy^T + A`  를 계산합니다.

.. c:function:: int gsl_blas_cgerc (const gsl_complex_float alpha, const gsl_vector_complex_float * x, const gsl_vector_complex_float * y, gsl_matrix_complex_float * A)
              int gsl_blas_zgerc (const gsl_complex alpha, const gsl_vector_complex * x, const gsl_vector_complex * y, gsl_matrix_complex * A)

  행렬 :math:`A` 대해, 컬례 랭크-1 갱신 :math:`A = \alpha xy^H + A` 를 계산합니다.

.. c:function:: int gsl_blas_ssyr (CBLAS_UPLO_t Uplo, float alpha, const gsl_vector_float * x, gsl_matrix_float * A)
              int gsl_blas_dsyr (CBLAS_UPLO_t Uplo, double alpha, const gsl_vector * x, gsl_matrix * A)

  대칭 행렬 :math:`A` 대해, 대칭 랭크-1 갱신 :math:`A = \alpha xx^T + A` 를 계산합니다. 
  행렬 :math:`A` 는 대칭 행렬이기 때문에, 상삼각 부분이나 하삼각 부분만 저장해도 됩니다.  
  :code:`Uplo` 가 :code:`CblasUpper` 일 때, 행렬 :math:`A` 는 상삼각 행렬과 대각 성분들이 사용되고,  
  :code:`CblasLower` 라면, :math:`A` 는 하삼각 행렬과 대각 성분들이 사용됩니다.


.. c:function:: int gsl_blas_cher (CBLAS_UPLO_t Uplo, float alpha, const gsl_vector_complex_float * x, gsl_matrix_complex_float * A)
              int gsl_blas_zher (CBLAS_UPLO_t Uplo, double alpha, const gsl_vector_complex * x, gsl_matrix_complex * A)

  에르미트 행렬 :math:`A` 대해, 에르미트 랭크-1 갱신 :math:`A = \alpha xx^H + A` 를 계산합니다. 
  행렬 :math:`A` 는 에르미트 행렬이기 때문에, 상삼각 부분이나 하삼각 부분만 저장해도 됩니다.  
  :code:`Uplo` 가 :code:`CblasUpper` 일 때, 행렬 :math:`A` 는 상삼각 행렬과 대각 성분들이 사용되고,  
  :code:`CblasLower` 라면, :math:`A` 는 하삼각 행렬과 대각 성분들이 사용됩니다. 
  대각 성분의 복소 성분들은 자동적으로 0으로 가정하고 참고되지 않습니다. 

.. c:function:: int gsl_blas_ssyr2 (CBLAS_UPLO_t Uplo, float alpha, const gsl_vector_float * x, const gsl_vector_float * y, gsl_matrix_float * A)
              int gsl_blas_dsyr2 (CBLAS_UPLO_t Uplo, double alpha, const gsl_vector * x, const gsl_vector * y, gsl_matrix * A)

  대칭 행렬 :math:`A` 대해, 대칭 랭크-2 갱신 :math:`A = \alpha xy^T + \alpha yx^T + A` 를 계산합니다. 
  행렬 :math:`A` 는 대칭 행렬이기 때문에, 상삼각 부분이나 하삼각 부분만 저장해도 됩니다.  
  :code:`Uplo` 가 :code:`CblasUpper` 일 때, 행렬 :math:`A` 는 상삼각 행렬과 대각 성분들이 사용되고,  
  :code:`CblasLower` 라면, :math:`A` 는 하삼각 행렬과 대각 성분들이 사용됩니다.

.. c:function:: int gsl_blas_cher2 (CBLAS_UPLO_t Uplo, const gsl_complex_float alpha, const gsl_vector_complex_float * x, const gsl_vector_complex_float * y, gsl_matrix_complex_float * A)
              int gsl_blas_zher2 (CBLAS_UPLO_t Uplo, const gsl_complex alpha, const gsl_vector_complex * x, const gsl_vector_complex * y, gsl_matrix_complex * A)

  에르미트 행렬 :math:`A` 대해, 에르미트 랭크-2갱신 :math:`A = \alpha xy^H + \alpha yx^H + A` 를 계산합니다. 
  행렬 :math:`A` 는 에르미트 행렬이기 때문에, 상삼각 부분이나 하삼각 부분만 저장해도 됩니다.  
  :code:`Uplo` 가 :code:`CblasUpper` 일 때, 행렬 :math:`A` 는 상삼각 행렬과 대각 성분들이 사용되고,  
  :code:`CblasLower` 라면, :math:`A` 는 하삼각 행렬과 대각 성분들이 사용됩니다. 
  대각 성분의 복소 성분들은 자동으로 0으로 가정하고 참고되지 않습니다. 

Level 3 BLAS 인터페이스
-------------------------
.. c:function:: int gsl_blas_sgemm (CBLAS_TRANSPOSE_t TransA, CBLAS_TRANSPOSE_t TransB, float alpha, const gsl_matrix_float * A, const gsl_matrix_float * B, float beta, gsl_matrix_float * C)
              int gsl_blas_dgemm (CBLAS_TRANSPOSE_t TransA, CBLAS_TRANSPOSE_t TransB, double alpha, const gsl_matrix * A, const gsl_matrix * B, double beta, gsl_matrix * C)
              int gsl_blas_cgemm (CBLAS_TRANSPOSE_t TransA, CBLAS_TRANSPOSE_t TransB, const gsl_complex_float alpha, const gsl_matrix_complex_float * A, const gsl_matrix_complex_float * B, const gsl_complex_float beta, gsl_matrix_complex_float * C)
              int gsl_blas_zgemm (CBLAS_TRANSPOSE_t TransA, CBLAS_TRANSPOSE_t TransB, const gsl_complex alpha, const gsl_matrix_complex * A, const gsl_matrix_complex * B, const gsl_complex beta, gsl_matrix_complex * C)

  행렬-행렬 사이의 곱과 합 :math:`C =\alpha op(A)op(B) + \beta C` 를 계산합니다.
  :code:`op(A) = A, A^T, A.h` 이고 :code:`TransA` = :code:`CblasNoTrans` , :code:`CblasTrans` , :code:`CblasConjTrans` 가 가능합니다.
  :math:`TransB` 같은 인자를 사용가능합니다.

.. c:function:: int gsl_blas_ssymm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, float alpha, const gsl_matrix_float * A, const gsl_matrix_float * B, float beta, gsl_matrix_float * C)
              int gsl_blas_dsymm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, double alpha, const gsl_matrix * A, const gsl_matrix * B, double beta, gsl_matrix * C)
              int gsl_blas_csymm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, const gsl_complex_float alpha, const gsl_matrix_complex_float * A, const gsl_matrix_complex_float * B, const gsl_complex_float beta, gsl_matrix_complex_float * C)
              int gsl_blas_zsymm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, const gsl_complex alpha, const gsl_matrix_complex * A, const gsl_matrix_complex * B, const gsl_complex beta, gsl_matrix_complex * C)

  행렬-행렬 사이의 곱과 합을 계산합니다. 
  :code:`Side` 가 :math:`CblasLeft`  일 때 :math:`C =\alpha AB + \beta C` 를,
  :math:`CblsRight` 면 :math:`C =\alpha BA + \beta C` 를 계산합니다. 
  행렬 :math:`A` 는 대칭 행렬이어야 합니다.  
  :code:`Uplo` 가 :code:`CblasUpper` 때, 행렬 :math:`A` 는 상삼각 행렬과 대각 성분들이 사용되고,  
  :code:`CblasLower` 때, 행렬 :math:`A` 는 하삼각 행렬과 대각 성분들이 사용됩니다. 
  대각 성분의 복소 성분들은 자동적으로 0으로 가정하고 참고되지 않습니다. 


.. c:function:: int gsl_blas_chemm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, const gsl_complex_float alpha, const gsl_matrix_complex_float * A, const gsl_matrix_complex_float * B, const gsl_complex_float beta, gsl_matrix_complex_float * C)
              int gsl_blas_zhemm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, const gsl_complex alpha, const gsl_matrix_complex * A, const gsl_matrix_complex * B, const gsl_complex beta, gsl_matrix_complex * C)

  행렬-행렬 곱을 계산합니다.  
  :code:`Side` 가 :math:`CblasLeft` 일 때 :math:`B= \alpha op(A)B` 를, 
  :code:`CblsRight` 면 :math:`B=\alpha Bop(A)` 를 계산합니다. 
  행렬 :math:`A` 는 에르미트 행렬이어야 합니다.  
  :code:`Uplo` 가 :code:`CblasUpper` 때, 행렬 :math:`A` 는 상삼각 부분과 대각 부분이 사용되고, 
  :code:`CblasLower` 때, 하삼각 부분과 대각 부분이 사용됩니다. 
  허수 성분의 대각 성분은 자동으로 0으로 취급됩니다.

.. c:function:: int gsl_blas_strmm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, float alpha, const gsl_matrix_float * A, gsl_matrix_float * B)
              int gsl_blas_dtrmm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, double alpha, const gsl_matrix * A, gsl_matrix * B)
              int gsl_blas_ctrmm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_complex_float alpha, const gsl_matrix_complex_float * A, gsl_matrix_complex_float * B)
              int gsl_blas_ztrmm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_complex alpha, const gsl_matrix_complex * A, gsl_matrix_complex * B)

  행렬-행렬 곱을 계산합니다.  
  :code:`Side` 가 :math:`CblasLeft` 일 때 :math:`B = \alpha op(A)B` 를,  
  :math:`CblasRight` 면 :math:`B = \alpha B op(A)` 를 계산합니다. 
  행렬 :math:`A` 는 삼각행렬이어햐 하고, 
  :code:`TransA` 가 :code:`CblasNoTrans` , :code:`CblasTrans` , :code:`CblasConkTrans` 인 경우 
  각각 :code:`op(A) = A, A^T, A.h` 를 의미합니다. 
  :code:`Uplo` 가 :code:`CblasUpper` 인 경우 행렬 :math:`A` 는 상삼각 부분이 사용되고,  
  :code:`CblasLower` 인 경우 :math:`A` 는 하삼각 부분이 사용됩니다.
  만약, :math:`Diag` 가 :code:`CblasNonUnit` 라면 행렬 :math:`A` 는 대각 성분이 사용되고,  
  :code:`CblasUnit` 라면 유니터리 행렬로 취급하여 대각 성분은 참고되지 않습니다.

.. c:function:: int gsl_blas_strsm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, float alpha, const gsl_matrix_float * A, gsl_matrix_float * B)
              int gsl_blas_dtrsm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, double alpha, const gsl_matrix * A, gsl_matrix * B)
              int gsl_blas_ctrsm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_complex_float alpha, const gsl_matrix_complex_float * A, gsl_matrix_complex_float * B)
              int gsl_blas_ztrsm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t TransA, CBLAS_DIAG_t Diag, const gsl_complex alpha, const gsl_matrix_complex * A, gsl_matrix_complex * B)

  역행렬의 행렬곱을 계산합니다.  
  :code:`Side`  가 :math:`CblasLeft` 일 때 :math:`B=\alpha op(inv(A))B` 를, 
  :math:`CblasRight` 경우에는 :math:`B=\alpha B op(inv(A))` 를 계산합니다. 
  행렬 :math:`A` 는 삼각 행렬이어야 하고 
  :code:`TransA` 가 :code:`CblasNoTrans` , :code:`CblasTrans` , :code:`CblasConkTrans` 인 경우 
  각각 :code:`op(A) = A, A^T, A.h` 를 의미합니다.  
  :code:`Uplo` 가 :code:`CblasUpper` 인 경우 행렬 :math:`A` 는 상삼각 부분이 사용되고,  
  :code:`CblasLower` 인 경우 :math:`A` 는 하삼각 부분이 사용됩니다. 
  만약, :math:`Diag` 가 :code:`CblasNonUnit` 라면 행렬 :math:`A` 는 대각 성분이 사용되고,  
  :code:`CblasUnit` 라면 유니터리 행렬로 취급하여 취급하여 대각 성분은 참고되지 않습니다.


.. c:function:: int gsl_blas_ssyrk (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, float alpha, const gsl_matrix_float * A, float beta, gsl_matrix_float * C)
              int gsl_blas_dsyrk (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, double alpha, const gsl_matrix * A, double beta, gsl_matrix * C)
              int gsl_blas_csyrk (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, const gsl_complex_float alpha, const gsl_matrix_complex_float * A, const gsl_complex_float beta, gsl_matrix_complex_float * C)
              int gsl_blas_zsyrk (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, const gsl_complex alpha, const gsl_matrix_complex * A, const gsl_complex beta, gsl_matrix_complex * C)

  대칭 행렬 :math:`C` 랭크-k 갱신을 계산합니다.  
  :code:`Trans` 가 :code:`CblasNoTrans` 라면 :math:`C = \alpha AA^T  + \beta C`  을,  
  :code:`CblasTrans`  면 :math:`C = \alpha A^T A + \beta C` 를 계산합니다. 
  행렬 :math:`C` 대칭 행렬이기 때문에 상삼각이나 하삼각 부분만 저장해도 됩니다.  
  :code:`Uplo` 가 :code:`CblasUpper` 인 경우  행렬 :math:`C` 상삼각 부분과 대각 부분이 사용되고,  
  :code:`CblasLower` 라면 :math:`C` 의 하삼각 부분과 대각 부분이 사용됩니다. 

.. c:function:: int gsl_blas_cherk (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, float alpha, const gsl_matrix_complex_float * A, float beta, gsl_matrix_complex_float * C)
              int gsl_blas_zherk (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, double alpha, const gsl_matrix_complex * A, double beta, gsl_matrix_complex * C)

  에르미트 행렬 :math:`C` 랭크-k 갱신을 계산합니다. :code:`Trans` 가 :code:`CblasNoTrans` 라면  
  :math:`C = \alpha AA^H  + \beta C` 을, :code:`CblasTrans` 면 :math:`C = \alpha A^H A + \beta C` 를 계산합니다. 
  행렬 :math:`C` 에르미트 행렬이기 때문에 상삼각이나 하삼각 부분만 저장해도 됩니다. 
  :code:`Uplo` 가 :code:`CblasUpper` 행렬 :math:`C` 상삼각 부분과 대각 부분이 사용되고,
  :code:`CblasLower`  라면 :math:`C` 의 하삼각 부분과 대각 부분이 사용됩니다. 

.. c:function:: int gsl_blas_ssyr2k (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, float alpha, const gsl_matrix_float * A, const gsl_matrix_float * B, float beta, gsl_matrix_float * C)
              int gsl_blas_dsyr2k (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, double alpha, const gsl_matrix * A, const gsl_matrix * B, double beta, gsl_matrix * C)
              int gsl_blas_csyr2k (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, const gsl_complex_float alpha, const gsl_matrix_complex_float * A, const gsl_matrix_complex_float * B, const gsl_complex_float beta, gsl_matrix_complex_float * C)
              int gsl_blas_zsyr2k (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, const gsl_complex alpha, const gsl_matrix_complex * A, const gsl_matrix_complex * B, const gsl_complex beta, gsl_matrix_complex * C)

  대칭 행렬 :math:`C` 랭크-2k 갱신을 계산합니다.  
  :code:`Trans` 가 :code:`CblasNoTrans`  라면 :math:`C = \alpha AB^T + \alpha B A^T  + \beta C` 을,  
  :code:`CblasTrans`  면 :math:`C = \alpha A^T B+\alpha B^T A + \beta C` 를 계산합니다. 
  행렬 :math:`C` 대칭 행렬이기 때문에 상삼각이나 하삼각 부분만 저장해도 됩니다.  
  :code:`Uplo` 가 :code:`CblasUpper` 인 경우 행렬 :math:`C` 상삼각 부분과 대각 부분이 사용되고,  
  :code:`CblasLower` 라면 :math:`C` 의 하삼각 부분과 대각 부분이 사용됩니다. 

.. c:function:: int gsl_blas_cher2k (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, const gsl_complex_float alpha, const gsl_matrix_complex_float * A, const gsl_matrix_complex_float * B, float beta, gsl_matrix_complex_float * C)
              int gsl_blas_zher2k (CBLAS_UPLO_t Uplo, CBLAS_TRANSPOSE_t Trans, const gsl_complex alpha, const gsl_matrix_complex * A, const gsl_matrix_complex * B, double beta, gsl_matrix_complex * C)


    에르미트 행렬 :math:`C` 의 랭크-2k 갱신을 계산합니다.
    :code:`Trans` 가 :code:`CblasNoTrans` 라면
    :math:`C = \alpha AB^T + \alpha B A^T  + \beta C` 을, 
    :code:`CblasTrans`  면 :math:`C = \alpha A^T B+\alpha B^T A + \beta C` 를 계산합니다.
    행렬 :math:`C` 에르미트 행렬이기 때문에 상삼각이나 하삼각 부분만 저장해도 됩니다.
    :code:`Uplo` 가 :code:`CblasUpper` 라면 행렬 :math:`C` 의 상삼각 부분과 대각 부분이 사용되고,
    :code:`CblasLower` 라면 :math:`C` 의 하삼각 부분과 대각 부분이 사용됩니다. 

예제
=========

다음 프로그램은 Level-3 BLAS 함수 DGEMM를 
사용해 두 개의 행렬의 곱을 계산합니다.

.. math::

      \left(
      \begin{matrix}
        0.11&0.12&0.13 \\
        0.21&0.22&0.23
      \end{matrix}
      \right)
      \left(
      \begin{matrix}
        1011&1012 \\
        1021&1022 \\
        1031&1031
      \end{matrix}
      \right)
      =
      \left(
      \begin{matrix}
        367.76&368.12 \\
        674.06&674.72
      \end{matrix}
      \right)


행렬은 배열의 C 표준 순서에 따라, 
열을 기준으로 배열합니다.

.. include:: examples/blas.c
   :code:

다음은 프로그램의 출력 결과입니다.

.. include:: examples/blas.txt
   :code:


참고문헌과 추가자료
-------------------------
기존 인터페이스 표준과 업데이트 된 인터페이스 표준을 모두 포함한 BLAS 표준에 대한 자료는 
BLAS 홈페이지 및 BLAS 기술 포럼 웹 사이트에서 온라인으로 확인할 수 있습니다.

* `BLAS Homepage <http://www.netlib.org/blas/>`_ 
* `BLAS Technical Forum <http://www.netlib.org/blas/blast-forum/>`_ 


BLAS의 Level 1,2,3의 자세한 사양을 확안하고 싶다면 다음 문서를 확인하시길 바랍니다.

* C. Lawson, R. Hanson, D. Kincaid, F. Krogh, “Basic Linear Algebra Subprograms for Fortran Usage”, 
  ACM Transactions on Mathematical Software, Vol.: 5 (1979), Pages 308–325.
* J.J. Dongarra, J. DuCroz, S. Hammarling, R. Hanson, “An Extended Set of Fortran Basic Linear Algebra Subprograms”, 
  ACM Transactions on Mathematical Software, Vol.: 14, No.: 1 (1988), Pages 1–32.
* J.J. Dongarra, I. Duff, J. DuCroz, S. Hammarling, “A Set of Level 3 Basic Linear Algebra Subprograms”, 
  ACM Transactions on Mathematical Software, Vol.: 16 (1990), Pages 1–28.

마지막 두 개 문서의 postscript 버전은 http://www.netlib.org/blas/ 에서 확인할 수 있습니다. 
Fortran BLAS 라이브러리의 CBLAS 이식 버전의 정보도 동일한 곳에서 사용할 수 있습니다.

