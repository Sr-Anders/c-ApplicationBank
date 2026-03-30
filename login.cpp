#include <iostream>
#include <string>
bool verifInicioSesion(std::string usuarioCorrecto, int claveCorrecta);
float conversion(float saldo, float tasa);
void transfer(float a,float b, float &cuentaDescuento, float &cuentaAumento, float monto) {
    cuentaDescuento = a - monto;
    cuentaAumento = b + monto;
}
int main() {
    std::string usuarioCorrecto = "usuario";
    int claveCorrecta = 123456;
    int intentoClave;
    std::string intentoUsuario;
    int opcionMenu = 1;
    int opcionMenuSaldo;
    int opcionMenuTransf;
    int opcionMenuServicio;
    int opcionMenuServicioIf;
    int tipoDeCuenta;
    float monto;
    float cuentaCorriente = 5000;
    float cuentaAhorro = 1000;
    float tasa = 480;
    float factElec = 100;
    float pagFactElec;
    float factAgua = 200;
    float pagFactAgua;
    float factInternet = 300;
    float pagFactInternet;
    float cuentaD;
    float cuentaA;
        if (verifInicioSesion(usuarioCorrecto, claveCorrecta)) {
            while(opcionMenu != 0) {
                std::cout <<"**MENU PRINCIPAL**" << std::endl;
                std::cout << std::endl;
                std::cout <<"#1 Consulta de saldo" << std::endl;
                std::cout <<"#2 Transferencias entre cuentas propias" << std::endl;
                std::cout <<"#3 Pagos de servicios" << std::endl;
                std::cout <<"#0 Salir del programa" << std::endl;
                std::cout << std::endl;                
                std::cout << "INGRESA EL NUMERO DE LA OPCION ELEGIDA: ";
                std::cin >> opcionMenu;
                std::cout << std::endl;
                switch(opcionMenu){
                    case 1:
                        std::cout << "**CONSULTA DE SALDO**" << std::endl;
                        std::cout << std::endl;
                        std::cout << "Cuenta corriente: BS " << cuentaCorriente << std::endl;
                        std::cout << "Cuenta de ahorro: BS " << cuentaAhorro << std::endl; 
                        std::cout << std::endl;
                        std::cout << "*ELIGE:" << std::endl;
                        std::cout << std::endl;
                        std::cout << "#1 Equivalencia en dolares" << std::endl;
                        std::cout << "#0 Volver al menu principal" << std::endl;
                        std::cout << std::endl;
                        std::cin >> opcionMenuSaldo;
                        std::cout << std::endl;
                        while(opcionMenuSaldo != 0) {
                            if(opcionMenuSaldo == 1){
                                std::cout << "**CONSULTA DE SALDO**" << std::endl;
                                std::cout << std::endl;
                                std::cout << "Tasa: BS " << tasa << std::endl;
                                std::cout << std::endl;
                                float result = conversion(cuentaCorriente, tasa);
                                std::cout << "Cuenta corriente: $ " << result << std::endl;
                                float result2 = conversion(cuentaAhorro, tasa);
                                std::cout << "Cuenta de ahorro: $ " << result2 << std::endl;
                                std::cout << std::endl;
                                std::cout << "*ELIGE:" << std::endl;
                                std::cout << std::endl;
                                std::cout << "#2 Volver a saldo en bolivares" << std::endl;
                                std::cout << "#0 Volver al menu principal" << std::endl;
                                std::cout << std::endl;
                                std::cin >> opcionMenuSaldo;
                                std::cout << std::endl;
                                while (opcionMenuSaldo == 2){
                                    std::cout << "**CONSULTA DE SALDO**" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "Cuenta corriente: BS " << cuentaCorriente << std::endl;
                                    std::cout << "Cuenta de ahorro: BS " << cuentaAhorro << std::endl; 
                                    std::cout << std::endl;
                                    std::cout << "*ELIGE:" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "#1 Equivalencia en dolares" << std::endl;
                                    std::cout << "#0 Volver al menu principal" << std::endl;
                                    std::cout << std::endl;
                                    std::cin >> opcionMenuSaldo;
                                    std::cout << std::endl;                             
                                }
                            } else if(opcionMenuSaldo == 2){
                                opcionMenu = opcionMenuSaldo;
                            } else {
                                opcionMenu = opcionMenuSaldo;
                            }
                        }
                    break;
                    case 2:
                        std::cout << "**TRANSFERENCIA ENTRE CUENTAS PROPIAS**" << std::endl;
                        std::cout << std::endl;
                        std::cout << "#1 Cuenta corriente a cuenta de ahorro" << std::endl;
                        std::cout << "#2 Cuenta de ahorro a cuenta de corriente" << std::endl; 
                        std::cout << std::endl;
                        std::cout << "INGRESE EL NUMERO DE LA OPCION ELEGIDA: "; 
                        std::cin >> opcionMenuTransf;
                        std::cout << std::endl;
                        if (opcionMenuTransf == 1) {
                            std::cout << "**CUENTA CORRIENTE A CUENTA DE AHORRO**" << std::endl;
                            std::cout << std::endl;
                            std::cout << "INGRESE MONTO: ";
                            std::cin >> monto;
                            transfer(cuentaCorriente, cuentaAhorro, cuentaD, cuentaA, monto);
                            std::cout << std::endl;
                            std::cout << "**CUENTA CORRIENTE A CUENTA DE AHORRO**" << std::endl;
                            std::cout << std::endl;
                            std::cout << "*Se transfirieron exitosamente: BS " << monto << " desde su cuenta corriente a su cuenta de ahorro." << std::endl;
                            std::cout << std::endl;
                            std::cout << "*El saldo de su cuenta corriente es de: BS " << cuentaD << std::endl;
                            std::cout << "*El saldo de su cuenta de ahorro es de: BS " << cuentaA << std::endl;
                            std::cout << std::endl;
                            std::cout << "INGRESE CUALQUIER NUMERO PARA VOLVER AL MENU PRINCIPAL: ";
                            std::cin >> opcionMenuTransf;
                            std::cout << std::endl;
                        } else if(opcionMenuTransf == 2){
                            std::cout << "**CUENTA DE AHORRO A CUENTA CORRIENTE**" << std::endl;
                            std::cout << std::endl;
                            std::cout << "INGRESE MONTO: ";
                            std::cin >> monto;
                            transfer(cuentaAhorro, cuentaCorriente, cuentaD, cuentaA, monto) ;   
                            std::cout << std::endl;
                            std::cout << "**CUENTA DE AHORRO A CUENTA CORRIENTE**" << std::endl;
                            std::cout << std::endl;
                            std::cout << "*Se transfirieron exitosamente: BS " << monto << " desde su cuenta de ahorro a su cuenta corriente." << std::endl;
                            std::cout << std::endl;
                            std::cout << "*El saldo de su cuenta corriente es de: BS " << cuentaA << std::endl;
                            std::cout << "*El saldo de su cuenta de ahorro es de: BS " << cuentaD << std::endl;
                            std::cout << std::endl;
                            std::cout << "INGRESE CUALQUIER NUMERO PARA VOLVER AL MENU PRINCIPAL: ";
                            std::cin >> opcionMenuTransf;
                        }
                        break;
                    case 3:
                        opcionMenuServicio = opcionMenu;
                        while (opcionMenuServicio != 0) {
                            std::cout << "**PAGOS DE SERVICIOS**" << std::endl;
                            std::cout << std::endl;
                            std::cout << "#1 Electricidad" << std::endl;
                            std::cout << "#2 Agua" << std::endl;
                            std::cout << "#3 Internet" << std::endl;
                            std::cout << "#0 Salir al menu principal" << std::endl; 
                            std::cout << std::endl;
                            std::cout << "INGRESE EL NUMERO DEL SERVICIO QUE DESEA PAGAR: "; 
                            std::cin >> opcionMenuServicio;
                            std::cout << std::endl;
                            if (opcionMenuServicio == 1) {
                                std::cout << "**ELECTRICIDAD**" << std::endl;
                                std::cout << std::endl;
                                std::cout << "Su factura para el mes de marzo es de: BS " << factElec << std::endl;
                                std::cout << std::endl;
                                std::cout << "**TIPO DE CUENTA** " << std::endl;
                                std::cout << std::endl;
                                std::cout << "#1 Cuenta corriente" <<std::endl;
                                std::cout << "#2 Cuenta ahorro" <<std::endl;
                                std::cout << std::endl;
                                std::cout << "INGRESE LA OPCION DEL TIPO DE CUENTA PARA EL PAGO DE SERVICIO: ";
                                std::cin >> tipoDeCuenta;
                                std::cout << std::endl;
                                std::cout << "INGRESE MONTO: ";
                                std::cin >> pagFactElec;
                                std::cout << std::endl;
                                if (tipoDeCuenta == 1) {
                                    cuentaCorriente = cuentaCorriente - pagFactElec;
                                    factElec = factElec - pagFactElec;
                                    std::cout << "*OPERACION EXITOSA*" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de: BS " << pagFactElec << " desde su cuenta corriente" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << factElec << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El saldo actual de su cuenta corriente posterior al pago del servicio es de: BS " << cuentaCorriente << std::endl;
                                } else if (tipoDeCuenta == 2) {
                                    cuentaAhorro = cuentaAhorro - pagFactElec;
                                    factElec = factElec - pagFactElec;
                                    std::cout << "**OPERACION EXITOSA**" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de: BS " << pagFactElec << " desde su cuenta de ahorro" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << factElec << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El saldo actual de su cuenta de ahorro posterior al pago del servicio es de: BS " << cuentaAhorro << std::endl;
                                }
                                std::cout << std::endl;
                                std::cout << "INGRESE CUALQUIER NUMERO PARA VOLVER AL MENU DE PAGOS DE SERVICIOS: ";
                                std::cin >> opcionMenuServicioIf;
                            } else if (opcionMenuServicio == 2) {
                                std::cout << "**AGUA**" << std::endl;
                                std::cout << std::endl;
                                std::cout << "Su factura para el mes de marzo es de: BS " << factAgua << std::endl;
                                std::cout << std::endl;
                                std::cout << "**TIPO DE CUENTA**" << std::endl;
                                std::cout << std::endl;
                                std::cout << "#1 Cuenta corriente" << std::endl;
                                std::cout << "#2 Cuenta ahorro" << std::endl;
                                std::cout << std::endl;
                                std::cout << "INGRESE LA OPCION DEL TIPO DE CUENTA PARA EL PAGO DE SERVICIO: ";
                                std::cin >> tipoDeCuenta;
                                std::cout << std::endl;
                                std::cout << "INGRESE MONTO: ";
                                std::cin >> pagFactAgua;
                                std::cout << std::endl;
                                if (tipoDeCuenta == 1) {
                                    cuentaCorriente = cuentaCorriente - pagFactAgua;
                                    factAgua = factAgua - pagFactAgua;
                                    std::cout << "**OPERACION EXITOSA**" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de: BS " << pagFactAgua << " desde su cuenta corriente" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << factAgua << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El saldo actual de su cuenta corriente posterior al pago del servicio es de: BS " << cuentaCorriente << std::endl;
                                    std::cout << std::endl;
                                } else if (tipoDeCuenta == 2) {
                                    cuentaAhorro = cuentaAhorro - pagFactAgua;
                                    factAgua = factAgua - pagFactAgua;
                                    std::cout << "**OPERACION EXITOSA**" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de: BS " << pagFactAgua << " desde su cuenta de ahorro" << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << factAgua << std::endl;
                                    std::cout << "*El saldo actual de su cuenta de ahorro posterior al pago del servicio es de: BS " << cuentaAhorro << std::endl;
                                }
                                std::cout << std::endl;
                                std::cout << "INGRESE CUALQUIER NUMERO PARA VOLVER AL MENU DE PAGOS DE SERVICIOS: ";
                                std::cin >> opcionMenuServicioIf;
                            } else if (opcionMenuServicio == 3) {
                                std::cout << std::endl;
                                std::cout << "**INTERNET**" <<std::endl;
                                std::cout << std::endl;
                                std::cout << "Su factura para el mes de marzo es de: BS " << factInternet << std::endl;
                                std::cout << std::endl;
                                std::cout << "**TIPO DE CUENTA**" << std::endl;
                                std::cout << std::endl;
                                std::cout << "#1 Cuenta corriente" <<std::endl;
                                std::cout << "#2 Cuenta ahorro" <<std::endl;
                                std::cout << std::endl;
                                std::cout << "INGRESE EL NUMERO DEL TIPO DE CUENTA PARA EL PAGO DE SERVICIO: ";
                                std::cin >> tipoDeCuenta;
                                std::cout << std::endl;
                                std::cout << "INGRESE MONTO: ";
                                std::cin >> pagFactInternet;
                                std::cout << std::endl;
                                if (tipoDeCuenta == 1) {
                                    cuentaCorriente = cuentaCorriente - pagFactInternet;
                                    factInternet = factInternet - pagFactInternet;
                                    std::cout << "**OPERACION EXITOSA**" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de: BS " << pagFactInternet << " desde su cuenta corriente" << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << factInternet << std::endl;
                                    std::cout << "*El saldo actual de su cuenta corriente posterior al pago del servicio es de: BS " << cuentaCorriente << std::endl;
                                } else if (tipoDeCuenta == 2) {
                                    cuentaAhorro = cuentaAhorro - pagFactInternet;
                                    factInternet = factInternet - pagFactInternet;
                                    std::cout << "**OPERACION EXITOSA**" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de " << pagFactInternet << " desde su cuenta de ahorro" << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << factInternet << std::endl;
                                    std::cout << "*El saldo actual de su cuenta de ahorro posterior al pago del servicio es de: BS " << cuentaAhorro << std::endl;
                                }
                                std::cout << std::endl;
                                std::cout << "INGRESE CUALQUIER NUMERO PARA VOLVER AL MENU DE PAGOS DE SERVICIOS: ";
                                std::cin >> opcionMenuServicioIf;
                            }
                        }     
                        break;
                    default:   
                        break;
                }    
            }               
        }
return 0;
}
bool verifInicioSesion(std::string usuarioCorrecto, int claveCorrecta){
    std::string intentoUsuario;
    int intentoClave;
    for (int i = 0; i < 3; i++) {
        std::cout << "**INICIO DE SESION**" << std::endl;
        std::cout << std::endl;
        std::cout << "Introduzca su nombre de usuario: ";
        std::cin >> intentoUsuario;
        std::cout << std::endl;
        std::cout << "Introduzca su clave: ";
        std::cin >> intentoClave;
        std::cout << std::endl;
        if ( intentoUsuario == usuarioCorrecto && intentoClave == claveCorrecta){
            return true;
        }
    std::cout << "Su usuario o clave son incorrectos, Intentos restantes: " << (2 - i) << std::endl;
    std::cout << std::endl;
    }
    return false;
}
float conversion(float saldo, float tasa){
    if (tasa == 0){
        std::cout << "No se puede dividir por cero" << std::endl;
        return 0;
    }
    return saldo / tasa;
}
