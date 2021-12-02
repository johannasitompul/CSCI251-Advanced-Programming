#ifndef MYTEMPLATES_H
#define MYTEMPLATES_H

// sort functions
template <typename T>
bool compareX(T a, T b) { return a.getX() < b.getX(); }

template <typename T>
bool compareY(T a, T b) { return a.getY() < b.getY(); }

template <typename T>
bool compareZ(T a, T b) { return a.getZ() < b.getZ(); }

template <typename T>
bool comparePt1(T a, T b) { return a.getPt1() < b.getPt1(); }

template <typename T>
bool comparePt2(T a, T b) { return a.getPt2() < b.getPt2(); }

template <typename T>
bool compareDistLength(T a, T b) { return a.getScalarValue() < b.getScalarValue(); }

#endif