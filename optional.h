#pragma once
#include <assert.h>

template <typename T>
class optional {

public:
	optional() {
		m_initialize = false;
	}

	optional(T& other) {
		m_object = other;
		m_initialize = true;
	}

	optional(const T& other) {
		m_object = other;
		m_initialize = true;
	}

	optional(T&& other) {
		m_object = other;
		m_initialize = true;
	}

	T& value() {
		assert(m_initialize);
		return m_object;
	}

	bool hasValue() const
	{
		return m_initialize;
	}

	void reset()
	{
		m_initialize = false;
	}

	T* operator->() {
		assert(m_initialize);
		return &m_object;
	}

	T& operator*() {
		assert(m_initialize);
		return m_object;
	}

	void operator=(const T& other) {
		m_object = other;
		m_initialize = true;
	}

	explicit operator bool() const {
		return m_initialize;
	}

private:
	T			m_object;
	bool		m_initialize;
};