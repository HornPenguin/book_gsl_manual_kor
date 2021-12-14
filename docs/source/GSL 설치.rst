
**********************************
GSL 설치
**********************************

많은 GNU 프로젝트의 결과물들이 source code 형태로 배포 되고 있습니다. 어떤 프로젝트들의 경우 release된 설치 파일(.exe, .msi, .deb, .rpm)을 통한 배포도 하고 있지만, GSL 라이브러리의 경우는 공식적으로 소스코드를 이용한 베포를 사용하고 있습니다. 상기한 설치파일을 제공하지 않는 프로젝트들도 존재하는 만큼 이러한 설치 방법을 알아두면, 나중에 다른  GNU 프로젝트들을 사용할 때 도움이 됩니다.
 
Windows, Linux, Mac에서 사전 컴파일 된 라이브러리가 존재합니다. 
Windows에서는 `Cygwin <http://www.cygwin.com/>`_ 의 일부분으로 존재하고 Linux 등에서는 베포판의 패키지 저장소에 있습니다. 
해당 파일을 사용할 수도 있고 소스코드를 실제 컴파일해서 설치할 수도 있습니다. 유의점은 이러한 사전 컴파일 라이브러리는 공식 베포가 아니라는 점입니다. 예를 들어서 **Ubuntu** 환경에서 ``apt search libgsl`` 을 사용해 저장소에서 해당 라이브러리를 검색할 경우, 다음과 같은 결과를 볼 수 있습니다. (06-29-2021 확인)

.. code-block:: bash

    libgsl-dbg/focal 2.5+dfsg-6build1 amd64
    GNU Scientific Library (GSL) -- debug symbols package

    libgsl-dev/focal 2.5+dfsg-6build1 amd64
    GNU Scientific Library (GSL) -- development package

    libgsl23/focal 2.5+dfsg-6build1 amd64
    GNU Scientific Library (GSL) -- library package

    libgslcblas0/focal 2.5+dfsg-6build1 amd64
    GNU Scientific Library (GSL) -- blas library package

    libocamlgsl-ocaml/focal 1.19.1-2build3 amd64
    GNU scientific library for OCaml

    libocamlgsl-ocaml-dev/focal 1.19.1-2build3 amd64
    GNU scientific library for OCaml


현 시점에서 최신 베포 버전은 ``2.7`` 입니다. 이렇듯 사전 컴파일된 라이브러리는 최신 버전을 충실히 반영하지 못합니다. 때문에 소스코드를 이용한 설치 방법을 알아두어야 할 필요가 있습니다.

GSL 다운로드 
-----------------

GSL은 `Main GNU FTP site <ftp://ftp.gnu.org/gnu/gsl/>`_ 나 가까운 `GNU mirror site <http://ftpmirror.gnu.org/gsl/>`_  에서 소스코드를 내려받을 수 있습니다.

현재 가장 최신버전은 2021년 6월 1일에 배포된 ``gsl-2.7`` 버전 입니다. 가장 최신 버전의 라이브러리를 다운로드 하고 싶다면, 다음과 같이 위의 ftp 링크에서 가장 최신 버전의 파일을 내려받거나.

.. code-block:: bash

    gsl-X.Y.tar.gz
    gsl-X.Y.tar.gz.sig

자동으로 최신 버전으로 업데이트 되는 파일을 내려받을 수도 있습니다.

.. code-block:: bash

    gsl-lastest.tar.gz


웹 브라우저를 통해 파일을 다운 받거나 터미널에서 받고 싶으면 ``wget``  명령어를 사용하면 됩니다. 다음은 ``gsl-lastes.tar.gz`` 을 다운 받을 수 있는 명령어입니다.

.. code-block:: 

    $ wget https://ftp.gnu.org/gnu/gsl/gsl-lastest.tar.gz


GSL 설치(Unbuntu)
-----------------

GSL의 설치는 다운로드 받은 압축 파일 내의 ``INSTALL``  파일에 잘 기술 되어 있습니다. 본 내용은 ``INSTALL``  파일의 일부를 기술한 것입니다. 추가적인 선택 사항이나 다른 OS에서의 설치는 ``INSTALL``  파일을 참고하시길 바랍니다.

본 라이브러리는 표준 GNU 설치 절차(GNU installation procedure)를 따릅니다. 표준 GNU 설치 절차는 다음의 6가지 단계로 이루어져있습니다.

1. Prerequisites
2. Downnloading the source
3. Configuration
4. Building
5. Testing(optional)
6. Final install

Prerequisites
~~~~~~~~~~~~~~~~~~~~~~

소스코드 형태의 프로젝트를 설치하기 위해서는 먼저 이러한 소스코드들을 컴파일 할 수 있는 컴파일러가 필요합니다. 일반적으로 GNU 프로젝트를 설치할 때에는 GCC(Gnu Compiler Collection)을 기본으로 사용합니다. 다음을 터미널 창에 입력하면 ``gcc`` 의 설치 유무를 알 수 있습니다.

.. code-block:: bash

    $ gcc
 
만약,  ``gcc`` 가 설치되어있다면, 
 
.. code-block:: bash

    gcc: fatal error: no input files
    compliation terminated


의 메세지가 뜰 것입니다. 

.. code-block:: bash

    $ gcc -v


를 입력하면 설치된 ``gcc`` 의 버전을 확인 할 수 있습니다. 일반적으로 최신 버전의 프로그램 사용이 권장되므로 다음을 입력해 ``gcc`` 의 업그레이드 버전이 있는지 확인하고 이를 업데이트 합니다.

.. code-block:: bash

    $ sudo apt update
    $ sudo apt upgrade


만약 설치되어있지 않다면,  ``gcc`` 를 설치해 주어야합니다. Ubuntu의 기본 저장소에서 이는 ``build-essential`` 패키지 내에 포함되어 있습니다. 다음을 입력해  ``build-essential`` 를 설치하면 필요한 ``gcc`` ,``g++`` ,``make`` 등의 여러 컴파일러와 유틸리티를 설치 할 수 있습니다.

다음을 입력해 ``build-essential`` 패키지를 설치합니다.

.. code-block:: bash

    $ sudo apt update
    $ sudo apt install build-essential


Downloading Source
~~~~~~~~~~~~~~~~~~~~~~

위에서 설명한 FTP 사이트에서 ``.tar.gz`` 파일을 다운로드하고, 이를 다음의 명령어를 통해 압축을 해제합니다.

.. code-block:: bash

    $ tar -xvzf gsl-lastest.tar.gz


이제 압축을 해제한 디렉토리로 들어갑시다.

.. code-block:: bash

    $ cd ./gsl-lastest

 
Configuration
~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: bash

    $ ./configure

를 입력하면 자동으로 시스템 설치 환경을 위한 ``Makefile`` 을 만들어 냅니다. 이 과정은 시간이 조금 걸립니다. 

Building & Test
~~~~~~~~~~~~~~~~~~~~~~

``config``  작업이 끝나면 만들어진 ``Makefile`` 을 이용해 소스코드를 컴파일 합니다. ``build-essential`` 에 포함된 ``make``  유틸리티가 이 작업을 해줍니다. 다음을 입력합시다.

.. code-block:: bash

    $ make

선택사항으로 ``make check`` 라는 명령어로 패키지에 제공된 자가 검증을 진행할 수도 있습니다. (일반적으로 방금 컴파일 과정을 거처 생성된, 미설치된 이진 코드를 사용합니다.)

Final install
~~~~~~~~~~~~~~~~~~~~~~
 
``make``  작업이 끝났으면 다음을 입력해 이를 설치합니다.

.. code-block:: bash

    $ sudo make install


6 단계까지 마무리하면 GSL의 설치는 끝납니다. 기본으로 설치된 위치는 ``/usr/local/lib`` 입니다. 이 폴더 안에는 다음과 같은 ``.so``  동적 라이브러리가 담겨있습니다. 컴퓨터 환경에 따라 해당 디렉토리에 담겨있는 라이브러리는 다양할 수 있습니다.

.. code-block:: bash

    User@COMPUTERNNAME:~$ ls -l /usr/local/lib
    total 47072
    -rw-r--r-- 1 root root  28142836 Jul  5 22:43 libgsl.a
    -rwxr-xr-x 1 root root       917 Jul  5 22:43 libgsl.la
    lrwxrwxrwx 1 root root        16 Jul  5 22:43 libgsl.so -> libgsl.so.25.1.0
    lrwxrwxrwx 1 root root        16 Jul  5 22:43 libgsl.so.25 -> libgsl.so.25.1.0
    -rwxr-xr-x 1 root root  16451032 Jul  5 22:43 libgsl.so.25.1.0
    -rw-r--r-- 1 root root   2255578 Jul  5 22:43 libgslcblas.a
    -rwxr-xr-x 1 root root       948 Jul  5 22:43 libgslcblas.la
    lrwxrwxrwx 1 root root        20 Jul  5 22:43 libgslcblas.so -> libgslcblas.so.0.0.0
    lrwxrwxrwx 1 root root        20 Jul  5 22:43 libgslcblas.so.0 -> libgslcblas.so.0.0.0
    -rwxr-xr-x 1 root root   1330608 Jul  5 22:43 libgslcblas.so.0.0.0
    drwxr-xr-x 2 root root      4096 Jul  5 22:43 pkgconfig


이 라이브러리를 이용해 프로그램을 작성하기 위해서는 링커가 해당 라이브러리에 접근할 수 있어야 합니다. 때문에 이러한 위치를 링커에게 알려주어야 합니다.

먼저, ``sudo ldconfig -v`` 를 입력해 ``/usr/local/lib`` 가 있는지 확인합니다. 
해당 파일이 없다면, 별도의 설정이 필요합니다. 다양한 방법이 존재합니다.

``LIBDIR = /usr/local/lib`` 

* 실행 중, 환경 변수 ``LD_LIBRARY_PATH`` 에 ``LIBDIR``  추가하기
* 링크 과정에서 환경 변수 ``LD_RUN_PATH`` 에 ``LIBDIR``  추가하기
* ``-Wl, -rpath -Wl, LIBDIR``  옵션을 링크에 넣기
* 관리자 권한을 얻은 후 ``/etc/ld.so.conf/``  디렉토리에 ``LIBDIR``  이 있는 파일 추가하기

마지막 방법은 ``libc.conf`` 을 만들어 주면 됩니다. 파일이름은 중요하지 않습니다. ``.conf`` 파일은 1 줄에 각각 ``.so``  동적 라이브러리 파일들이 있는 디렉토리 경로를 작성하면 됩니다. 일반적으로 이 방법이 권장됩니다. 최신 Ubuntu에서는 기본으로 ``libc.conf``  파일이 ``/etc/ld.so.conf/``  디렉토리에 있어 별도의 설정없이 라이브러리를 활용 가능합니다. ``libc.conf``  파일의 내용은 다음과 같습니다.

.. code-block:: bash

    # libc default configuration
    /usr/local/lib

**환경 변수에 추가하기**

``bash`` 창에 다음을 입력하면 환경 변수 ``LD_LIBRARY_PATH`` 에 위치를 추가할 수 있습니다. 

.. code-block:: bash

    LD_LIBRARY_PATH=${LD_LIBRARY_PARH}:/usr/local/lib
    export LD_LIBRARY_PATH 


그러나 이 방법은 새로운 ``bash`` 창을 열 때마다 별도로 입력해 주어야합니다. 때문에, 계정의 홈 디렉토리에 있는 ``.bashrc`` 파일의 끝에 다음의 문구를 추가해줍니다 [#bashrc]_ .


.. code-block:: bash

    LD_LIBRARY_PATH=${LD_LIBRARY_PARH}:/usr/local/lib
    export LD_LIBRARY_PATH 


재부팅 후나 ``$ source ~/.bashrc`` 를 입력하면 정상적으로 사용이 가능합니다.

.. rubric:: 각주

.. [#bashrc] 해당 파일은 bash가 시작할 때 실행되는 명령어를 기술하고 있습니다(*).
