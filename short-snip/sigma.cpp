//! sum of [s, t]
const auto sigma = [](const auto s_, const auto t_) { return (s_ + t_) * (t_ - s_ + 1) / 2; };
