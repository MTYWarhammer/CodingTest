#pragma once
class Object //== Monobehavior
{
public:
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render() = 0;
	virtual void Destory() = 0;
	Object();
	virtual ~Object(); //object²¨Áú¶§ °°ÀÌ ²¨Áü
private:
};

