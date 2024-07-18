#ifndef NEVERMORE_UTILITY_NONCOPYABLE_H
#define NEVERMORE_UTILITY_NONCOPYABLE_H

namespace sf {

// 继承此基类以删除默认copy语义，得益于空基类优化，此继承不会有额外开销
// copy from Muduo
struct Noncopyable {
public:
    Noncopyable(const Noncopyable&) = delete;
    Noncopyable& operator=(const Noncopyable&) = delete;

    Noncopyable(Noncopyable&&) noexcept = default;
    Noncopyable& operator=(Noncopyable&&) noexcept = default;

protected:
    Noncopyable() = default;
    virtual ~Noncopyable() = default;
};

} // namespace sf

#endif // NEVERMORE_UTILITY_NONCOPYABLE_H
