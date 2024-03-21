#include <algorithm>
#include <iostream>
#include <unordered_map>

class FrequencyTracker {
 public:
  FrequencyTracker() {}

  void add(int number) {
    if (m_[number]>0) {
        --freq_m_[m_[number]];
    }
    ++m_[number];
    ++freq_m_[m_[number]];
  }

  void deleteOne(int number) {
    int cur_freq = m_[number];
    if (cur_freq > 0) {
        --freq_m_[cur_freq];
    }
    m_[number] = std::max(m_[number]-1, 0);
    if (m_[number]>0) {
        ++freq_m_[m_[number]];
    }
  }

  bool hasFrequency(int frequency) {
    return freq_m_[frequency] > 0;
  }

 private:
    std::unordered_map<int, int> m_;
    std::unordered_map<int, int> freq_m_;
};