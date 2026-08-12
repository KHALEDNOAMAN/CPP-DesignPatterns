// Specification Pattern - Composable business rules
template<typename T>
class Specification {
public:
    virtual bool isSatisfied(T item) = 0;
};
template<typename T>
class AndSpec : public Specification<T> {
    Specification<T>& a; Specification<T>& b;
public:
    AndSpec(Specification<T>& a, Specification<T>& b) : a(a), b(b) {}
    bool isSatisfied(T item) override { return a.isSatisfied(item) && b.isSatisfied(item); }
};