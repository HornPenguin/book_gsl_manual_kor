
이 단원에서는  극 마티유 함수와 방사형 마티유 함수를 계산하는 함수들을 서술합니다.
이 함수들의 특성 값의 계산 기능도 같이 제공합니다. 마트유 함수는 다음 두 미분 방정식의
해로 주어집니다.

.. math::

      {{d^2 y}\over{d v^2}}& + (a - 2q\cos 2v)y  = 0 \\
      {{d^2 f}\over{d u^2}}& - (a - 2q\cosh 2u)f  = 0


극 마티유 함수 :math:`ce_r(x,q)` 와 :math:`se_r(x,q)` 은 각각 첫번째 미분 방정식의
짝수, 홀수 번째 주기 함수해 입니다. 
이 첫번째 미분 방정식은 마티유 방정식으로도 알려저 있습니다.
이 해들은 짝수와 홀수에 대해 각각 특성값의 이산 배열값들 
:math:`a = a_r(q)` 와 :math:`a = b_r(q)` 에 대해서만 존재합니다. 


방사형 마티유 함수 :math:`Mc^{(j)}_{r}(z,q)` 와 :math:`Ms^{(j)}_{r}(z,q)` 는
두번째 미분 방정식의 해로 이 미분 방성직은 수정 마티유 방정식으로 알려져 있습니다.
1, 2, 3, 그리고 4차 방사 마티유 함수들은 계수 :math:`j` 로 표현됩니다. 
:math:`j` 는 1, 2, 3, 4 값을 가집니다.

마티유 함수에 대한 더 자세한 정보를 얻고 싶다면 Abramowitz and Stegunn, Chapter 20을 참조하길 바랍니다.
이 함수들은 헤더 파일 :code:`gsl_sf_mathieu.h` 에 정의되어 있습니다.

마티유 함수 작업 공간 (Mathieu Function Workspace)
-----------------------------------------------------

마티유 함수들은 단일 차수나 복수 차수의 함수가 있으며, 
배열에 기반한 방법을 통해 계산할 수 있습니다. 
배열 기반 함수들은 사전 정의된 작업 공간이 필요합니다.

.. type:: gsl_sf_mathieu_workspace

이 공간은 배열 기반 방법을 위한 작업 공간입니다.

.. function:: gsl_sf_mathieu_workspace * gsl_sf_mathieu_alloc (size_t n, double qmax)

이 함수는 마티유 함수들의 배열 기반 방법을 위한 작업 공간을 반환합니다. 인자 :math:`n` :math:`qmax` 최대 계수와 공간에서 계산되는 마티유 함수의 :math:`q`  -값을 결정합니다.

.. function:: void gsl_sf_mathieu_free (gsl_sf_mathieu_workspace * work)

이 함수는 주어진 작업 공간 :math:`work` 를 해제합니다.

마티유 함수 특성 값 (Mathieu Function Characteristic Values)
-------------------------------------------------------------------

.. function:: int gsl_sf_mathieu_a (int n, double q)
              int gsl_sf_mathieu_a_e (int n, double q, gsl_sf_result * result)
              int gsl_sf_mathieu_b (int n, double q)
              int gsl_sf_mathieu_b_e (int n, double q, gsl_sf_result * result)

    각각, 마티유 함수 :math:`c e_n (q,x)`  와 :math:`s e_n (q,x)`  의 특성 값 :math:`a_n(q)`  와 :math:`b_n(q)`  을 계산합니다.

.. function:: int gsl_sf_mathieu_a_array (int order_min, int order_max, double q, gsl_sf_mathieu_workspace * work, double result_array[])
              int gsl_sf_mathieu_b_array (int order_min, int order_max, double q, gsl_sf_mathieu_workspace * work, double result_array[])

    마티유 함수의 특성 값 :math:`a_n(q)`  와 :math:`b_n(q)`  을 주어진 :math:`oreder_min` :math:`order_max`  사이 범위에 있는 :math:`n`  에 대해 계산합니다. 계산 결과는 :math:`result_array` 저장됩니다.

각 운동량 마티유 함수 (Angular Mathieu Functions)
-------------------------------------------------------------------

.. function:: int gsl_sf_mathieu_ce (int n, double q, double x)
              int gsl_sf_mathieu_ce_e (int n, double q, double x, gsl_sf_result * result)
              int gsl_sf_mathieu_se (int n, double q, double x)
              int gsl_sf_mathieu_se_e (int n, double q, double x, gsl_sf_result * result)

    각각, 각 운동량 마티유 함수 :math:`c e_n (q,x)`  와 :math:`s e_n (q,x)`  를 계산합니다.

.. function:: int gsl_sf_mathieu_ce_array (int nmin, int nmax, double q, double x, gsl_sf_mathieu_workspace * work, double result_array[])
              int gsl_sf_mathieu_se_array (int nmin, int nmax, double q, double x, gsl_sf_mathieu_workspace * work, double result_array[])

    각각, 각 운동량 마티유 함수 :math:`c e_n (q,x)`  와 :math:`s e_n (q,x)`  의 값을 주어진 :math:`nmin` :math:`nmax`  이 범위에 있는 :math:`n`  에 대해 계산합니다. 계산 결과는 :math:`result_array` 저장됩니다.


방사 마티유 함수 (Radial Mathieu Functions)
-------------------------------------------------

.. function:: int gsl_sf_mathieu_Mc (int j, int n, double q, double x)
              int gsl_sf_mathieu_Mc_e (int j, int n, double q, double x, gsl_sf_result * result)
              int gsl_sf_mathieu_Ms (int j, int n, double q, double x)
              int gsl_sf_mathieu_Ms_e (int j, int n, double q, double x, gsl_sf_result * result)

    각각, :math:`j` 종 :math:`n` 차수의 마티유 함수 :math:`M c_n^{(j)} (q,x)` 와 
    :math:`M s_n^{(j)} (q,x)` 를 계산합니다.

    :math:`j` 값은 :math:`1,2` 로 한정됩니다. 
    :math:`j=3, 4` 는 다음의 관계를 이용해 계산할 수 있습니다. 
    :math:`M_n^{(j)} =` :math:`Mc_n^{(j)}` 나 :math:`Ms_n^{(j)}` 에 대해, 
    :math:`M_n^{(3)} = M_n^{(1)} + i M_n^{(2)}` 와 :math:`M_n^{(4)} = M_n^{(1)} - i M_n^{(2)}` .

.. function:: int gsl_sf_mathieu_Mc_array (int j, int nmin, int nmax, double q, double x, gsl_sf_mathieu_workspace * work, double result_array[])
              int gsl_sf_mathieu_Ms_array (int j, int nmin, int nmax, double q, double x, gsl_sf_mathieu_workspace * work, double result_array[])

    :math:`j` 메티유 함수의 값을 주어진 :math:`nmin` 와 :math:`nmax` 범위에 있는 
    :math:`n` 에 대해 계산합니다. 계산 결과는 :math:`result_array` 에 저장됩니다.
