./test.x
export CODECOV_TOKEN="52216a41-594e-427c-a1dd-24f270b026a2"
lcov --no-external --capture --directory . --output-file cov.info
genhtml cov.info --output-directory covinfo
bash <(curl -s https://codecov.io/bash) -f cov.info