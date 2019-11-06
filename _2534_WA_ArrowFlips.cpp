/**
 *  Problem:    http://coj.uci.cu/24h/problem.xhtml?pid=2534
 *  Programmer: Michael Duarte
 *  Date:       September 24th 2019
 *  Note:       Segment struct's previous and after pointers were initially thought to point to the
 *              the vector/container of the Segments, but getting vector.back() returned a reference
 *              and I was having problems pointing to references.
 *                  I.e. currentS->after = &(vector.back()).
 *              Therefore I decided to use smart_ptr instead.
 */

#include<iostream>
#include <vector>
#include <memory>
#include <algorithm>  // std::sort

using namespace std;

struct Segment {
  char c;
  int startI;
  int endI;
  Segment *previous = nullptr;
  Segment *after = nullptr;

  Segment(char newChar, int start, Segment *prev) : c(newChar), startI(start), previous(prev) { }
  int getCount() const { return endI - startI; }
  int getPrevCount() const {
    return previous == nullptr ? 0 : previous->getCount();
  }
  int getAfterCount() const {
    return after == nullptr ? 0 : after->getCount();
  }
  void print() {
    // cout << this ;
    cout << " => '" << c << "' from: " << startI << ", to: " << endI << " (";
    cout <<  getCount() << ")";
    // cout << "previous: " << (previous ? previous : 0) << ", after: " << (after ? after : 0);
    cout << endl;
  }
};

// Passing shared_ptr by reference is OK under controlled circumstances, semantics are lost though.
// https://stackoverflow.com/a/8385581
bool sortSegmentsDesc(const shared_ptr<Segment> &s1, const shared_ptr<Segment> &s2) {
  return s1->getCount() > s2->getCount();
}

void print(const vector<shared_ptr<Segment>> &segments) {
  for (auto &segment : segments) {
    segment->print();
  }
}

bool tryPreviousFirst(const shared_ptr<Segment> &segment, int mMoves) {
  int prevCount = segment->getPrevCount();
  int afterCount = segment->getAfterCount();
  if (prevCount > 0 && prevCount <= mMoves) {
    return true;
  }
  if (afterCount > 0 && afterCount <= mMoves) {
    return true;
  }
  return segment->getPrevCount() < segment->getAfterCount();
}

int longestRunOfArrowsWithMaxMoves(
  const vector<shared_ptr<Segment>> &segments, int maxMoves, bool preferMinorThan) {
  int longestRun = 0;
  shared_ptr<Segment> longestSegment = nullptr;
  int mMoves = maxMoves;
  // I have to be careful to pick the correct character for longer run since I am using pointers and
  // There is no way to restore the vector of segments to its initial state.
  char targetC = 
      segments.size() > 1 && segments[0]->getCount() == segments[1]->getCount() && preferMinorThan
          ? '<'
          : segments.front()->c;
  // cout << "Target char: " << targetC << endl;
  for (int i = 0; i < segments.size() && mMoves > 0; ++i) {
    const shared_ptr<Segment> &segment = segments[i];
    // cout << "Evaluating segment: "; segment->print(); 
    if (segment->c == targetC) {
      int segSize = segment->getCount();
      if (tryPreviousFirst(segment, mMoves) && segment->getPrevCount() > 0) {
        int prevSegSize = segment->getPrevCount();
        int delta = prevSegSize > mMoves ? mMoves : prevSegSize;
        mMoves -= delta;
        segment->previous->endI -= delta;
        if (segment->getPrevCount() == 0) {
          segment->previous = segment->previous->previous;
          while (segment->previous != nullptr && segment->previous->c == targetC) {
            delta -= segment->getPrevCount();
            segment->previous = segment->previous->previous;
          }
        }
        segment->startI -= delta;
        segSize += delta;
        --i;
      } else if (int afterSegSize = segment->getAfterCount() > 0) {
        int delta = afterSegSize > mMoves ? mMoves : afterSegSize;
        mMoves -= delta;
        segment->after->startI += delta;
        if (segment->getAfterCount() == 0) {
          segment->after = segment->after->after;
          while (segment->after != nullptr && segment->after->c == targetC) {
            delta += segment->getAfterCount();
            segment->after = segment->after->after;
          }
        }
        segment->endI += delta;
        segSize += delta;
        --i;
      }
      if (segSize >= longestRun) {
        longestRun = segSize;
        longestSegment = segment;
      }
    }
  }
  // cout << endl << "Longest segment (" << longestRun << "): ";
  // longestSegment->print();
  // print(segments);
  return longestRun;
}

int longestRunOfArrowsWithMaxMoves(const string &input, int maxMoves) {
  // cout << "Processing: " << input << " with " << maxMoves << " moves" << endl;
  vector<shared_ptr<Segment>> segments;
  Segment *currentS = nullptr;
  int minorThanCount = 0;
  for (int i = 0 ; i < input.length(); ++i) {
    if (input[i] == '<') {
      ++minorThanCount;
    }
    if (currentS == nullptr || currentS->c != input[i]) {
      segments.emplace_back(make_shared<Segment>(input[i], i, currentS));
      if (currentS != nullptr) {
        currentS->endI = i;
        currentS->after = (segments[segments.size() - 1]).get();
      }
      currentS = (segments[segments.size() - 1]).get();
    }
  }
  if (currentS != nullptr) {
    currentS->endI = input.length();
  }
  sort(segments.begin(), segments.end(), sortSegmentsDesc);
  // print(segments);
  return longestRunOfArrowsWithMaxMoves(segments, maxMoves, (minorThanCount*2 > input.length()));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int cases;
  cin >> cases;
  int maxMoves;
  string input;
  while (cases--) {
    cin >> maxMoves >> input;
    cout << longestRunOfArrowsWithMaxMoves(input, maxMoves) << endl;
  }
  return EXIT_SUCCESS;
}