#include <QString>

class FixedWidthString {
    mutable QString m_string;
    //! Ignored if negative.
    int m_maxLength;
    inline const QString& data() const {
        if (m_maxLength >= 0 && m_string.length() > m_maxLength)
            m_string.truncate(m_maxLength);
        return m_string;
    }
    inline QString& data() {
        if (m_maxLength >= 0 && m_string.length() > m_maxLength)
            m_string.truncate(m_maxLength);
        return m_string;
    }
public:
    explicit FixedWidthString(int maxLength = -1) : m_maxLength(maxLength) {}
    explicit FixedWidthString(const QString & str, int maxLength = -1) : m_string(str), m_maxLength(maxLength) {}
    operator const QString&() const { return data(); }
    operator QString&() { return data(); }
    QString* operator->() { return &data(); }
    const QString* operator->() const { return &data(); }
    QString& operator*() { return data(); }
    const QString& operator*() const { return data(); }
    FixedWidthString & operator=(const FixedWidthString& other) {
        m_string = *other;
        return *this;
    }
};
