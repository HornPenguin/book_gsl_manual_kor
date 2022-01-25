
addpackages = r'''

\usepackage{pdfpages}
\usepackage{multicol}
\usepackage{setspace}
\usepackage{imakeidx}
\usepackage{bookmark}
\usepackage{CJK}{CJKspace}
'''

preamble = r'''
\renewcommand{\hyperref}[2][]{#2}
%setspace 패키지 설정: CJK가 주인 문서에서 줄간격이 너무 좁을 때
\onehalfspacing
\setstretch{1.5} % custom spacing
%------------------------------------------------------------
'''

fontpkg= r'''

\setmainfont{Noto Serif CJK KR}
\setsansfont{Noto Sans CJK KR}
\setmonofont{Noto Sans Mono CJK KR}

'''

maketitle=r'''
\newpage
    \includepdf[pages=-]{Cover.pdf}
\newpage
\sphinxmaketitle
'''
# Void Resources============================================================================
# 15, 5.4
# 9.1, 9.3