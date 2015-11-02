\name{fdrcontrol-package}
\alias{fdrcontrol-package}
\alias{fdrcontrol}
\docType{package}
\title{
  False discovery rate filter with Benjamin–Hochberg procedure
}
\description{
    This library contain a function for FDR control.
}
\details{
  This library contain a function for FDR control. This is on created in order to extract data points that are significant in multiple testing. The function FDRcontrol takes in a vector of pvalues and the desired alpha value and output 0,1 for failed/passed.  
}
\author{
Douglas Wu, wckdouglas@gmail.com.

Maintainer: Douglas Wu <wckdouglas@gmail.com>
}
\references{
  https://www.urmc.rochester.edu/biostat/people/faculty/TuSite/FDR_procedure.pdf
  http://wckdouglas.github.io/mediator/feature/2015/05/12/BH_adjust.html
  http://wckdouglas.github.io/mediator/feature/2015/05/17/BH_adjust_updated.html
}
% Optionally other standard keywords, one per line,
% from the file KEYWORDS in the R documentation.
\keyword{ package }
\examples{
  FDRcontrol(pvalues,alpha) 
}
