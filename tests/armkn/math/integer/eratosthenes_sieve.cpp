#include <armkn/math/integer/eratosthenes_sieve.hpp>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("eratosthenes_sieve", "[math][math/integer]") {
  using vec = std::vector<bool>;
  CHECK(eratosthenes_sieve(1) == vec{0, 0});
  CHECK(eratosthenes_sieve(2) == vec{0, 0, 1});
  CHECK(eratosthenes_sieve(3) == vec{0, 0, 1, 1});
  CHECK(eratosthenes_sieve(4) == vec{0, 0, 1, 1, 0});
  CHECK(eratosthenes_sieve(5) == vec{0, 0, 1, 1, 0, 1});

  auto prime = eratosthenes_sieve(16);
  CHECK(prime.size() == 17);
  CHECK(prime[0] == 0);
  CHECK(prime[1] == 0);
  CHECK(prime[2] == true);
  CHECK(prime[3] == true);
  CHECK(prime[4] == 0);
  CHECK(prime[5] == true);
  CHECK(prime[6] == 0);
  CHECK(prime[7] == true);
  CHECK(prime[8] == 0);
  CHECK(prime[9] == 0);
  CHECK(prime[10] == 0);
  CHECK(prime[11] == true);
  CHECK(prime[12] == 0);
  CHECK(prime[13] == true);
  CHECK(prime[14] == 0);
  CHECK(prime[15] == 0);
  CHECK(prime[16] == 0);
}
