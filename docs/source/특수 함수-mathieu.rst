# 마티유 함수 (Mathieu Functions)


마티유 함수들은 단일 차수나 복수 차수의 함수가 있으며, 배열에 기반한 방법을 통해 계산할 수 있습니다. 배열 기반 함수들은 사전 정의된 작업 공간이 필요합니다.

마티유 함수 작업 공간 (Mathieu Function Workspace)
-------------------------

> type **gsl_sf_mathieu_workspace**

이 공간은 배열 기반 방법을 위한 작업 공간입니다.

> gsl_sf_mathieu_workspace * **gsl_sf_mathieu_alloc**(size_t *n*, double *qmax*)

이 함수는 마티유 함수들의 배열 기반 방법을 위한 작업 공간을 반환합니다. 인자  ``n``   ``qmax``  최대 계수와 공간에서 계산되는 마티유 함수의  :math:`q` -값을 결정합니다.

> void **gsl_sf_mathieu_free**(gsl_sf_mathieu_workspace * *work*)

이 함수는 주어진 작업 공간  ``work``  해제합니다.

마티유 함수 특성 값 (Mathieu Function Characteristic Values)
-------------------------

> int **gsl_sf_mathieu_a**(int *n*, double *q*)
> int **gsl_sf_mathieu_a_e**(int *n*, double *q*, gsl_sf_result * *result*)
> int **gsl_sf_mathieu_b**(int *n*, double *q*)
> int **gsl_sf_mathieu_b_e**(int *n*, double *q*, gsl_sf_result * *result*)

이 함수들은 각각, 마티유 함수  :math:`c e_n (q,x)` 와  :math:`s e_n (q,x)` 의 특성 값  :math:`a_n(q)` 와  :math:`b_n(q)` 을 계산합니다.

> int **gsl_sf_mathieu_a_array**(int *order_min*, int *order_max*, double *q*, igsl_sf_mathieu_workspace * *work*, double *result_array*[])
> int **gsl_sf_mathieu_b_array**(int *order_min*, int *order_max*, double *q*, igsl_sf_mathieu_workspace * *work*, double *result_array*[])

이 함수들은 마티유 함수의 특성 값  :math:`a_n(q)` 와  :math:`b_n(q)` 을 주어진  ``oreder_min``   ``order_max`` 사이 범위에 있는  :math:`n` 에 대해 계산합니다. 계산 결과는  ``result_array``  저장됩니다.

각 운동량 마티유 함수 (Angular Mathieu Functions)
-------------------------

> int **gsl_sf_mathieu_ce**(int *n*, double *q*, double *x*)<br>
> int **gsl_sf_mathieu_ce_e**(int *n*, double *q*, double *x*, gsl_sf_result * *result*)<br>
> int **gsl_sf_mathieu_se**(int *n*, double *q*, double *x*)<br>
> int **gsl_sf_mathieu_se_e**(int *n*, double *q*, double *x*, gsl_sf_result * *result*)

이 함수들은 각각, 각 운동량 마티유 함수  :math:`c e_n (q,x)` 와  :math:`s e_n (q,x)` 를 계산합니다.

> int **gsl_sf_mathieu_ce_array**(int *n*min, int *n*max, double *q*, double *x*, igsl_sf_mathieu_workspace * *work*, double *result_array*[])<br>
> int **gsl_sf_mathieu_se_array**(int *n*min, int *n*max, double *q*, double *x*, igsl_sf_mathieu_workspace * *work*, double *result_array*[])

이 함수들은 각각, 각 운동량 마티유 함수  :math:`c e_n (q,x)` 와  :math:`s e_n (q,x)` 의 값을 주어진  ``nmin``   ``nmax`` 이 범위에 있는  :math:`n` 에 대해 계산합니다. 계산 결과는  ``result_array``  저장됩니다.


방사 마티유 함수 (Radial Mathieu Functions)
-------------------------

> int **gsl_sf_mathieu_Mc**(int *j*, int *n*, double *q*, double *x*)<br>
> int **gsl_sf_mathieu_Mc_e**(int *j*, int *n*, double *q*, double *x*, gsl_sf_result * *result*)<br>
> int **gsl_sf_mathieu_Ms**(int *j*, int *n*, double *q*, double *x*)<br>
> int **gsl_sf_mathieu_Ms_e**(int *j*, int *n*, double *q*, double *x*, gsl_sf_result * *result*)

이 함수들은 각각,  ``j`` 종  ``n``  마티유 함수  :math:`M c_n^{(j)} (q,x)` 와  :math:`M s_n^{(j)} (q,x)` 를 계산합니다.

 ``j`` 값은  :math:`1,2`  로 한정됩니다.  :math:`j=3, 4` 는 다음의 관계를 이용해 계산할 수 있습니다.  :math:`M_n^{(j)} =`   :math:`Mc_n^{(j)}` 나  :math:`Ms_n^{(j)}` 에 대해,  :math:`M_n^{(3)} = M_n^{(1)} + i M_n^{(2)}` 와  :math:`M_n^{(4)} = M_n^{(1)} - i M_n^{(2)}` .

>  int **gsl_sf_mathieu_Mc_array**(int *j*, int *nmin*, int *nmax*, double *q*, double *x*, gsl_sf_mathieu_workspace * *work*, double *result_array*[])<br>
> int **gsl_sf_mathieu_Ms_array**(int *j*, int *nmin*, int *nmax*, double *q*, double *x*, gsl_sf_mathieu_workspace * *work*, double *result_array*[])

이 함수들은  ``j``  메티유 함수의 값을 주어진  ``nmin``   ``nmax`` 이 범위에 있는  :math:`n` 에 대해 계산합니다. 계산 결과는  ``result_array``  저장됩니다.
