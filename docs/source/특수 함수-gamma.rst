

다음 함수들은 완전/불완전 감마, 베타 함수를 다양한 팩토리얼에 대해, 계산합니다. 
이 단원의 함수들은 헤더 파일  ``gsl_sf_gamma.h`` 에 정의되어 있습니다.

 감마 함수 (Gamma Functions)
----------------------------------

감마 함수는 다음의 적분으로 정의되어 있습니다.

 :math:`$\Gamma (x) = \int_0^\infty t^{x-1} \exp(-t) dt` $

양의 정수  :math:`n` 에 대해, 이 함수는 팩토리얼과  :math:`\Gamma (n) = (n-1)!` 의 관계를 가집니다. 감마 함수에 관한 더 자세한 설명은 Abramowitz & Stegun, Chapter 6를 참조할 수 있습니다.

>double **gsl_sf_gamma**(double *x*)<br>
>int **gsl_sf_gamma_e**(double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`0` 이나 음의 정수가 아닌  :math:`x` 에 대해, 감마 함수  :math:`\Gamma(x)` 의 값을 계산합니다. 이 함수는 실수 Lanczos 방법을 사용합니다.  :math:`x` 의 최댓값은  :math:`\Gamma(x)` 가 오버 플로우 되지 않는 범위로 매크로  ``GSL_SF_GAMMA_XMAX``  주어져 있습니다. 이 값은  :math:`171.0` 입니다.

>double **gsl_sf_lngamma**(double *x*)<br>
>int **gsl_sf_lngamma_e**(double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`0` 이나 음의 정수가 아닌  :math:`x` 에 대해, 로그 감마 함수  :math:`\log(\Gamma(x))` 의 값을 계산합니다.  :math:`x<0` 에 대해,  :math:`\log(\Gamma(x))` 값이 반환되며, 이 값은  :math:`\log(|\Gamma(x)|)` 의 값과 같습니다. 이 함수는 실수 Lanczos 방법을 사용합니다.

>int **gsl_sf_lngamma_sgn_e**(double *x*, gsl_sf_result * *result_lg*, double * *sgn*)

이 함수는  :math:`0` 이나 음의 정수가 아닌  :math:`x` 에 대해, 감마 함수의 부호와 그 크기의 로그 값을 계산합니다. 이 함수는 실수 Lanczos 방법을 사용합니다. 감마 함수의 값과 그 오차는  ``result_lg``  두 요소와 다음의 관계를 사용해 계산합니다.  :math:`\Gamma(x) = sgn * \exp(result_lg)` .

>double **gsl_sf_gammastar**(double *x*)<br>
>int **gsl_sf_gammastar_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 regulated 감마 함수  :math:`\Gamma^* (x)` 를  :math:`x>0` 에 대해 계산합니다. 이 함수는 다음과 같이 주어집니다.

 :math:`$\Gamma^* (x) = \Gamma (x)/(\sqrt{2 \pi}x^{(x-1/2)} \exp(-x))` $
 :math:`$= (1+ \frac{1}{12x}+ \dots) \text{ for } x \rightarrow \infty` $

>double **gsl_sf_gammainv**(double *x*)<br>
>int **gsl_sf_gammainv_e**(double *x*, gsl_sf_result * *result*)

이 함수들은 실수 Lanczos 방법을 사용해 감마 함수의 역수,  :math:`1/\Gamma(x)`  값을 계산합니다.

>int **gsl_sf_lngamma_complex_e**(double *zr*, double *zi*, gsl_sf_result * *lnr*, gsl_sf_result * *arg*)

이 함수는 복소수 Lanczos 방법을 사용해, 주어진 복소수  :math:`z= z_r + i z_i` 에 대해,  :math:`\log(\Gamma(z))`  값을 계산합니다. 이때,  :math:`z` 는  :math:`0` 과 음의 정수가 아닌 복소수입니다.  :math:`lnr = \log|\Gamma(z)|` ,  :math:`arg = \text{arg}(\Gamma(z))` 이고,  :math:`arg` 는  :math:`(-\pi, \pi]`  범위의 값을 가집니다.  :math:`|z|` 가 매우 클 때,  ``arg`` 값이 정확히 정해지지 않을 수 있습니다. 이는  :math:`(-\pi, \pi]` 로 범위를 제약함으로써 필연적으로 생기는 절단점으로 인해 생깁니다. 이러한 상황은  ``GSL_ELOSS`` 오류에 속하는 상황입니다. 절대값  ``lnr`` 부분은 이러한 정밀도 저하를 격지 않습니다.

팩토리얼
-------------------------

양의 정수  :math:`n` 에 대해, 감마 함수를 이용해  :math:`n! = \Gamma(n+1)`  팩토리얼을  계산할 수 있습니다. 하지만, 아래의 함수들을 이용하는 것이 작은  :math:`n`  값들에 대해 더 효율적입니다. 이 함수들은 팩토리얼 값들을 하드 코딩된 테이블에 보관하고 있습니다.

>double **gsl_sf_fact**(unsigned int *n*)<br>
>int **gsl_sf_fact_e**(unsigned int *n*, gsl_sf_result * *result*)

이 함수들은 팩토리얼  :math:`n!` 를 계산합니다. 팩토리얼은 감마 함수와  :math:`n! = \Gamma(n+1)` 의 관계를 가지고 있습니다.  :math:`n` 의 최댓값은  :math:`n!` 이 오버플로우되지 않는 값으로 정해집니다. 이는 매크로  ``GSL_SF_FACT_NMAX``  정의되어 있고  :math:`170` 입니다.

>double **gsl_sf_doublefact**(unsigned int *n*)<br>
>int **gsl_sf_doublefact_e**(unsigned int *n*, gsl_sf_result * *result*)

이 함수들은 더블 팩토리얼  :math:`n!! = n(n-2)(n-4)\dots` 을 계산합니다.  :math:`n` 의 최댓값은  :math:`n!!` 이 오버플로 되지 않는 값으로 정해집니다. 이는 매크로  ``GSL_SF_DOUBLEFACT_NMAX``  정의되어 있고  :math:`297` 입니다.

>double **gsl_sf_lnfact**(unsigned int *n*)<br>
>int **gsl_sf_lnfact_e**(unsigned int *n*, gsl_sf_result * *result*)

이 함수들은  ``n`` 팩토리얼의 로그 값,  :math:`\log(n!)`  값을 계산합니다. 이 알고리즘은  :math:`n <170` 에서  :math:`\ln(\Gamma(n+1))`  값을 계산하는  ``gsl_sf_lngamma`` 다 빠릅니다. 하지만 큰  ``n``  대해서는 빠르지 않습니다.

>double **gsl_sf_lndoublefact**(unsigned int *n*)<br>
>int **gsl_sf_lndoublefact_e**(unsigned int *n*, gsl_sf_result * *result*)

이 함수들은  ``n``  대해, 더블 팩토리얼의 로그 값  :math:`\log(n!!)` 을 계산합니다.

>double **gsl_sf_choose**(unsigned int *n*, unsigned int *m*)<br>
>int **gsl_sf_choose_e**(unsigned int *n*, unsigned int *m*, gsl_sf_result * *result*)

이 함수들은 조합 계수  ``n choose m``  :math:`= n!/(m!(n-m!))` 의 값을 계산합니다.

>double **gsl_sf_lnchoose**(unsigned int *n*, unsigned int *m*)<br>
>int **gsl_sf_lnchoose_e**(unsigned int *n*, unsigned int *m*, gsl_sf_result * *result*)

이 함수들은 조합 계수  ``n choose m``  로그 값을 계산합니다. 이 값은  :math:`\log(n!) - \log(m!) - \log((n-m)!)` 과 같습니다.

>double **gsl_sf_taylorcoeff**(int *n*, double *x*)<br>
>int **gsl_sf_taylorcoeff_e**(int *n*, double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`x \geq0` ,  :math:`n \geq0` 에 대해, 테일러 계수  :math:`x^n/n!` 값을 계산합니다.

포흐하머 기호
-------------------------

>double **gsl_sf_poch**(double *a*, double *x*)<br>
>int **gsl_sf_poch_e**(double *a*, double *x*, gsl_sf_result * *result*)

이 함수들은 포흐하머 기호  :math:`(a)_x = \Gamma(a_x)/\Gamma(a)` 를 계산합니다. 포흐하머 기호는 아펠(Apell) 기호로도 알려져있으며,  :math:`(a,x)` 로 표기하기도 합니다.  :math:`a` 와  :math:`a+x` 가 음의 정수나  :math:`0` 일때, 해당 비의 극한 값이 반환됩니다.

>double **gsl_sf_lnpoch**(double *a*, double *x*)<br>
>int **gsl_sf_lnpoch_e**(double *a*, double *x*, gsl_sf_result * *result*)

이 함수들은 포흐하머 기호의ㅣ 로그값  :math:`\log((a)_x) = \log(\Gamma(a+x)/\Gamma(a))` 을 계산합니다.

>int **gsl_sf_lnpoch_sgn_e**(double *a*, double *x*, gsl_sf_result * *result*, double * *sgn*)

이 함수들은 포흐하머 기호의 부호와 그 크기의 로그값을 계산합니다. 계산되는 계수들은  :math:`result = \log(|(a)_x|)` 가 오차 값과 함께 계산되고,  :math:`(a)_x = \Gamma(a+x)/\Gamma(a)` 에 대해,  :math:`sgn = \text{sgn})(a)_x)` 을 계산합니다.


>double **gsl_sf_pochrel**(double *a*, double *x*)<br>
>int **gsl_sf_pochrel_e**(double *a*, double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`(a)_x = \Gamma(a+x)/\Gamma(a)` 에 대해,  :math:`((a)_x -1)/x` 값을 계산합니다.

불완전 감마 함수
-------------------------

>double **gsl_sf_gamma_inc**(double *a*, double *x*)<br>
>int **gsl_sf_gamma_inc_e**(double *a*, double *x*, gsl_sf_result * *result*)

이 함수들은 실수  :math:`a` 와  :math:`x \geq 0` 에 대해, 비정규화된 불완전 감마 함수  :math:`\Gamma(a,x) = \int_x^\infty t^{(a-1)} \exp(-t) dt`  값을 계산합니다.

>double **gsl_sf_gamma_inc_Q**(double *a*, double *x*)<br>
>int **gsl_sf_gamma_inc_Q_e**(double *a*, double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`a>0` 과  :math:`x \leq 0` 에 대해, 정규화된 불완전 감마 함수  :math:`Q(a,x) = 1.\Gamma(a) \int_x^\infty t^{(a-1)} \exp(-t) dt` 의 값을 계산합니다.

>double **gsl_sf_gamma_inc_P**(double *a*, double *x*)<br>
>int **gsl_sf_gamma_inc_P_e**(double *a*, double *x*, gsl_sf_result * *result*)

이 함수들은  :math:`a>0` 과  :math:`x \geq 0` 에 대해,  :math:`P(a,x) = 1-Q(a,x) = 1/\Gamma(a) \int_0^x t^{(a-1)} \exp(-t) dt` 값을 계산합니다.

Abramowtz & Stegun의 6.5단원, 불완전 감마 함수에서  :math:`P(a,x)`  표기를 씁니다. 

베타 함수
-------------------------


>double **gsl_sf_beta**(double *a*, double *b*)<br>
>int **gsl_sf_beta_e**(double *a*, double *b*, gsl_sf_result * *result*)

이 함수들은 베타함수  :math:`B(a,b) = \Gamma(a)\Gamma(b)/\Gamma(a+b)`  값을 계산합니다.  :math:`a,b` 는 음의 정수가 아니여야 합니다.

>double **gsl_sf_lnbeta**(double *a*, double *b*)<br>
>int **gsl_sf_lnbeta_e**(double *a*, double *b*, gsl_sf_result * *result*)

이 함수들은 베타 함수의 로그 값  :math:`\log(B(a,b))` 를 계산합니다.  :math:`a,b` 는 음의 정수가 아니여야 합니다.

불완전 베타 함수
-------------------------

>double **gsl_sf_beta_inc**(double *a*, double *b*, double *x*)<br>
>int **gsl_sf_beta_inc_e**(double *a*, double *b*, double *x*, gsl_sf_result * *result*)

이 함수들은 정규화된 불완전 베타함수  :math:`I_x (a,b) = B_x(a,b)/ B(a,b)` 를 계산합니다.  :math:`B_x(a,b)` 는  :math:`0 \leq x \leq 1` 에 대해 다음과 같이 정해집니다.

 :math:`$ B_x (a,b) = \int_0^x t^{a-1} (1-t)^{b-1} dt` $

이 값은  :math:`a>0, b>0` 에 대해, 연속 분수 전개를 이용해 계산됩니다. 다른 경우에는 다음의 관계를 이용해 계산합니다.

 :math:`$I_x (a,b,x) = (\frac{1}{a}) x^a \frac{_2F_1 (a, 1-b, a+1, x)}{B(a,b)}` $
