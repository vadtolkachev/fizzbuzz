./test.x
lcov --no-external --capture --directory . --output-file cov.info
genhtml cov.info --output-directory covinfo