
packagelist= {
    "kotex" : "",
    "afterpage" : "",
    "pagecolor" : "pagecolor=none",
    "tikz" : "",
    "tikzpagenodes" : "",
    "fix-cm" : "",
    "textpos" : "absolute, overlay",
}

#    "xeCJK" : "CJKspace",

packages = "\n".join(["\\usepackage[{}]{{{}}}".format(v, k) for k, v in packagelist.items()])

custom_setting = r'''

    \definecolor{coverbackground}{RGB}{209, 198, 161} 
    \definecolor{coverband}{RGB}{239, 190, 84}

    \newfontfamily\hangulfont{나눔명조}
    '''

cover_page = r'''
    \pagecolor{coverbackground}\afterpage{\nopagecolor}

    \begin{tikzpicture}[remember picture,overlay,shift={(current page.north west)}]
        \fill[coverband,yshift=-120mm] rectangle(\paperwidth,85mm);
    \end{tikzpicture}

    \vspace{-0.5cm}\hspace{2.5cm}\includegraphics[width=0.45\textwidth]{A_Slick_GNU_Logo.png}

    \begin{textblock*}{4.25cm}(15cm,5.4cm) % {block width} (coords) 
        \raggedright{
        \Huge\textbf{과학계산}\\
        \Huge\textbf{라이브러리}
        }\\
        \raggedleft\Large\textbf{v2.7}
    \end{textblock*}

    \begin{textblock*}{10cm}(9.1cm,9.3cm)
        \raggedleft
        \fontsize{32}{60}\selectfont \textbf{사용 설명서}
    \end{textblock*}

    \begin{center}
        \vfill
        \large \textbf{Mark Galassi \\ et al} \\
        \vspace{0.5cm}
        역: 김현성 \\
        \vspace{1.2cm}
        \Large \textbf{GNU Publication}
    \end{center}
'''
# 15, 5.4
# 9.1, 9.3
license_page = r'''
    원 영문 원서의 저작권 Copyright of the Original English Version:
    \noindent\textbf{Copyright (c)} Copyright © 1996-2021 The GSL Team.\\
    Permission is granted to copy, distribute and/or modify this document under the terms of the
    GNU Free Documentation License, Version 1.3 or any later version published by the Free Software
    Foundation; with the Invariant Sections being “GNU General Public License” and “Free Software
    Needs Free Documentation”, the Front-Cover text being “A GNU Manual”, and with the Back-
    Cover Text being (a) (see below). A copy of the license is included in the section entitled “GNU
    Free Documentation License”.
    (a) The Back-Cover Text is: “You have freedom to copy and modify this GNU Manual, like
    GNU software.” Printed copies of this manual can be purchased from Network Theory Ltd at
    http://www.network-theory.co.uk/gsl/manual/.
    The money raised from sales of the manual helps support the development of GSL

    \noindent\textbf{Copyright (c)}  2022  김현성. \\
    Permission is granted to copy, distribute and/or modify this document under 
    the terms of the GNU Free Documentation License, Version 1.3 or any later
    version published by the Free Software Foundation; with no  
    Invariant Sections, no Front-Cover Texts, and no Back-Cover Texts. 
    A copy of the license is included in the section entitled 
    "GNU 자유 문서 사용 허가서". \\~\\
    
    \noindent\textbf{Copyright (c)}  2022  김현성. \\
    GNU 자유 문서 사용 허가서 1.3판과 자유 소프트웨어 재단에서 발행한 이후의 갱신본의
    규정에 따라, 본 저작물의 복제, 베포 및 수정을 허가합니다. 변경 불가 부분, 앞 표지 구절과
    뒷 표지 구절은 없습니다. 이 허가서의 복사본은 "GNU 자유 문서 사용 허가서"로 지어진 단락에
    포함되어 있습니다.
    
    '''