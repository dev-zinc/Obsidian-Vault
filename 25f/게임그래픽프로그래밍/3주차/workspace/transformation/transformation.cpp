
#include <windows.h> 
#include <DirectXMath.h>
#include <iostream>
#include <iomanip>
std::ostream& XM_CALLCONV operator <<(std::ostream& os, DirectX::FXMVECTOR v) {
    DirectX::XMFLOAT4 dest;
    DirectX::XMStoreFloat4(&dest, v);
    os << "(" << dest.x << ", " << dest.y << ", " << dest.z << ", "
        << dest.w << ")";
    return os;
}
std::ostream& XM_CALLCONV operator <<(std::ostream& os, DirectX::FXMMATRIX m) {
    for (int i = 0; i < 4; ++i) {
        os << DirectX::XMVectorGetX(m.r[i]) << "\t";
        os << DirectX::XMVectorGetY(m.r[i]) << "\t";
        os << DirectX::XMVectorGetZ(m.r[i]) << "\t";
        os << DirectX::XMVectorGetW(m.r[i]) << std::endl;
    }
    return os;
}

int main() {
    if (!DirectX::XMVerifyCPUSupport()) {
        std::cout << "directx math not supported" << std::endl;
        return 0;
    }

    std::cout << std::fixed << std::setprecision(10);

    float theta = DirectX::XM_PIDIV4;
    DirectX::XMVECTOR Q = DirectX::XMVectorSet(0.0f, 0.0f, DirectX::XMScalarSin(theta / 2.f) * 1.0f, DirectX::XMScalarCos(theta / 2.f));
    // ((ux, uy, yz)*sin(theta/2), cos(theta/2))

    DirectX::XMMATRIX A = DirectX::XMMatrixAffineTransformation(
        DirectX::XMVECTOR({ 1.0f, 1.0f, 1.0f, 0.0f }),
        DirectX::XMVECTOR({ 0.0f, 0.0f, 0.0f, 0.0f }),
        Q,
        DirectX::XMVECTOR({ 0.0f, 0.0f, 0.0f, 0.0f }));

    std::cout << "A = " << std::endl << A << std::endl;

    DirectX::XMVECTOR X, Y;
    X = DirectX::XMVectorSet(-1.f, 1.f, 0.0f, 0.0f);
    Y = DirectX::XMVector3TransformNormal(X, A);

    std::cout << "X = " << std::endl << X << std::endl;
    std::cout << "Y = " << std::endl << Y << std::endl;

    DirectX::XMMATRIX A2 = DirectX::XMMatrixInverse(nullptr, A);
    X = DirectX::XMVector3TransformNormal(Y, A2);

    std::cout << "X = " << std::endl << X << std::endl;

    return 0;
}