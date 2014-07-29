#ifndef UTIL_H
#define UTIL_H

#define DEFINE_ACCESSORS(type, name, Name) \
private: \
type m_##name; \
public: \
inline type get##Name() { return m_##name; } \
inline void set##Name(const type name) { m_##name = name; } \

#endif