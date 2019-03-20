./test.x
lcov --capture --directory . --output-file cov.info
genhtml cov.info --output-directory covinfo