#include <iostream>
#include <string>
bool verifInicioSesion(struct entradas &entrada);
void transferencia (double &ctaDesc, double &ctaAum, double monto);
void conversion(double ctaCteBs, double ctaAroBs, double &ctaCteDs, double &ctaAroDs, double tasa);
void resta(double &cuenta, double monto, double &factura);
struct cuentas{
    double corriente = 5000.0; 
    double ahorro = 1000; 
    double corrienteDs;
    double ahorroDs; 
    double tasa = 0;
};
struct facturas{
    double electricidad = 100;
    double agua = 200;
    double internet = 300;
};
struct entradas{
    double monto;
    int opcMenPri = 1;
    int opcMenSal = 01;
    int opcMenTra = 0;
    int opcMenSer = 0;
    int opcMenSerIf = 0;
    int tipDeCue = 0;
    std::string usuarioCto = "a";
    int claveCto = 1;
    std::string usuarioInput;
    int claveInput;
};
int main() {
    cuentas miCuenta;
    entradas miEntrada;
    facturas miFactura;
    miEntrada.usuarioCto = "a";
    miEntrada.claveCto = 1;
    std::string intentoUsuario;
        if (verifInicioSesion(miEntrada)) {
            while(miEntrada.opcMenPri != 0) {
                std::cout <<"**MENU PRINCIPAL**" << std::endl;
                std::cout << std::endl;
                std::cout <<"#1 Consulta de saldo" << std::endl;
                std::cout <<"#2 Transferencias entre cuentas propias" << std::endl;
                std::cout <<"#3 Pagos de servicios" << std::endl;
                std::cout <<"#0 Salir del programa" << std::endl;
                std::cout << std::endl;                
                std::cout << "INGRESA EL NUMERO DE LA OPCION ELEGIDA: ";
                std::cin >> miEntrada.opcMenPri;
                std::cout << std::endl;
                switch(miEntrada.opcMenPri){
                    case 1:
                        std::cout << "**CONSULTA DE SALDO**" << std::endl;
                        std::cout << std::endl;
                        std::cout << "Cuenta corriente: BS " << miCuenta.corriente << std::endl;
                        std::cout << "Cuenta de ahorro: BS " << miCuenta.ahorro << std::endl; 
                        std::cout << std::endl;
                        std::cout << "*ELIGE:" << std::endl;
                        std::cout << std::endl;
                        std::cout << "#1 Equivalencia en dolares" << std::endl;
                        std::cout << "#0 Volver al menu principal" << std::endl;
                        std::cout << std::endl;
                        std::cin >> miEntrada.opcMenSal;
                        std::cout << std::endl;
                        while(miEntrada.opcMenSal != 0) {
                            if(miEntrada.opcMenSal == 1 && miCuenta.tasa > 0){
                                conversion(miCuenta.corriente, miCuenta.ahorro, miCuenta.corrienteDs, miCuenta.ahorroDs, miCuenta.tasa);
                                std::cout << "**CONSULTA DE SALDO**" << std::endl;
                                std::cout << std::endl;
                                std::cout << "Tasa: BS " << miCuenta.tasa << std::endl;
                                std::cout << std::endl;
                                std::cout << "Cuenta corriente: $ " << miCuenta.corrienteDs << std::endl;
                                std::cout << "Cuenta de ahorro: $ " << miCuenta.ahorroDs << std::endl;
                                std::cout << std::endl;
                                std::cout << "*ELIGE:" << std::endl;
                                std::cout << std::endl;
                                std::cout << "#2 Volver a saldo en bolivares" << std::endl;
                                std::cout << "#0 Volver al menu principal" << std::endl;
                                std::cout << std::endl;
                                std::cin >> miEntrada.opcMenSal;
                                std::cout << std::endl;
                                while (miEntrada.opcMenSal == 2){
                                    std::cout << "**CONSULTA DE SALDO**" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "Cuenta corriente: BS " << miCuenta.corriente << std::endl;
                                    std::cout << "Cuenta de ahorro: BS " << miCuenta.ahorro << std::endl; 
                                    std::cout << std::endl;
                                    std::cout << "*ELIGE:" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "#1 Equivalencia en dolares" << std::endl;
                                    std::cout << "#0 Volver al menu principal" << std::endl;
                                    std::cout << std::endl;
                                    std::cin >> miEntrada.opcMenSal;
                                    std::cout << std::endl;                             
                                }
                            } else if (miEntrada.opcMenSal == 1 && miCuenta.tasa <= 0){
                                std::cout << "No se puede dividir por cero" << std::endl;
                                std::cout << std::endl;
                                miEntrada.opcMenSal = 0;
                            } else if(miEntrada.opcMenSal == 2){
                                miEntrada.opcMenPri = miEntrada.opcMenSal;
                            } else {
                                miEntrada.opcMenPri = miEntrada.opcMenSal;
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
                        std::cin >> miEntrada.opcMenTra;
                        std::cout << std::endl;
                        if (miEntrada.opcMenTra == 1) {
                            std::cout << "**CUENTA CORRIENTE A CUENTA DE AHORRO**" << std::endl;
                            std::cout << std::endl;
                            std::cout << "INGRESE MONTO: ";
                            std::cin >> miEntrada.monto;
                            transferencia(miCuenta.corriente, miCuenta.ahorro, miEntrada.monto);
                            std::cout << std::endl;
                            std::cout << "**CUENTA CORRIENTE A CUENTA DE AHORRO**" << std::endl;
                            std::cout << std::endl;
                            std::cout << "*Se transfirieron exitosamente: BS " << miEntrada.monto << " desde su cuenta corriente a su cuenta de ahorro." << std::endl;
                            std::cout << std::endl;
                            std::cout << "*El saldo de su cuenta corriente es de: BS " << miCuenta.corriente << std::endl;
                            std::cout << "*El saldo de su cuenta de ahorro es de: BS " << miCuenta.ahorro << std::endl;
                            std::cout << std::endl;
                            std::cout << "INGRESE CUALQUIER NUMERO PARA VOLVER AL MENU PRINCIPAL: ";
                            std::cin >> miEntrada.opcMenTra;
                            std::cout << std::endl;
                        } else if(miEntrada.opcMenTra == 2){
                            std::cout << "**CUENTA DE AHORRO A CUENTA CORRIENTE**" << std::endl;
                            std::cout << std::endl;
                            std::cout << "INGRESE MONTO: ";
                            std::cin >> miEntrada.monto;
                            transferencia(miCuenta.ahorro, miCuenta.corriente, miEntrada.monto);   
                            std::cout << std::endl;
                            std::cout << "**CUENTA DE AHORRO A CUENTA CORRIENTE**" << std::endl;
                            std::cout << std::endl;
                            std::cout << "*Se transfirieron exitosamente: BS " << miEntrada.monto << " desde su cuenta de ahorro a su cuenta corriente." << std::endl;
                            std::cout << std::endl;
                            std::cout << "*El saldo de su cuenta corriente es de: BS " << miCuenta.corriente << std::endl;
                            std::cout << "*El saldo de su cuenta de ahorro es de: BS " << miCuenta.ahorro << std::endl;
                            std::cout << std::endl;
                            std::cout << "INGRESE CUALQUIER NUMERO PARA VOLVER AL MENU PRINCIPAL: ";
                            std::cin >> miEntrada.opcMenTra;
                        }
                        break;
                    case 3:
                        miEntrada.opcMenSer = miEntrada.opcMenPri;
                        while (miEntrada.opcMenSer != 0) {
                            std::cout << "**PAGOS DE SERVICIOS**" << std::endl;
                            std::cout << std::endl;
                            std::cout << "#1 Electricidad" << std::endl;
                            std::cout << "#2 Agua" << std::endl;
                            std::cout << "#3 Internet" << std::endl;
                            std::cout << "#0 Salir al menu principal" << std::endl; 
                            std::cout << std::endl;
                            std::cout << "INGRESE EL NUMERO DEL SERVICIO QUE DESEA PAGAR: "; 
                            std::cin >> miEntrada.opcMenSer;
                            std::cout << std::endl;
                            if (miEntrada.opcMenSer == 1) {
                                std::cout << std::endl;
                                std::cout << "**ELECTRICIDAD**" << std::endl;
                                std::cout << std::endl;
                                std::cout << "Su factura para el mes de marzo es de: BS " << miFactura.electricidad << std::endl;
                                std::cout << std::endl;
                                std::cout << "**TIPO DE CUENTA** " << std::endl;
                                std::cout << std::endl;
                                std::cout << "#1 Cuenta corriente" <<std::endl;
                                std::cout << "#2 Cuenta ahorro" <<std::endl;
                                std::cout << std::endl;
                                std::cout << "INGRESE LA OPCION DEL TIPO DE CUENTA PARA EL PAGO DE SERVICIO: ";
                                std::cin >> miEntrada.tipDeCue;
                                std::cout << std::endl;
                                std::cout << "INGRESE MONTO: ";
                                std::cin >> miEntrada.monto;
                                std::cout << std::endl;
                                if (miEntrada.tipDeCue == 1) {
                                    resta(miCuenta.corriente, miEntrada.monto, miFactura.electricidad);
                                    std::cout << "*OPERACION EXITOSA*" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de: BS " << miEntrada.monto << " desde su cuenta corriente" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << miFactura.electricidad << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El saldo actual de su cuenta corriente posterior al pago del servicio es de: BS " << miCuenta.corriente << std::endl;
                                } else if (miEntrada.tipDeCue == 2) {
                                    resta(miCuenta.ahorro, miEntrada.monto, miFactura.electricidad);
                                    std::cout << "**OPERACION EXITOSA**" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de: BS " << miEntrada.monto << " desde su cuenta de ahorro" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << miFactura.electricidad << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El saldo actual de su cuenta de ahorro posterior al pago del servicio es de: BS " << miCuenta.ahorro << std::endl;
                                }
                                std::cout << std::endl;
                                std::cout << "INGRESE CUALQUIER NUMERO PARA VOLVER AL MENU DE PAGOS DE SERVICIOS: ";
                                std::cin >> miEntrada.opcMenSerIf;
                            } else if (miEntrada.opcMenSer == 2) {
                                std::cout << std::endl;
                                std::cout << "**AGUA**" << std::endl;
                                std::cout << std::endl;
                                std::cout << "Su factura para el mes de marzo es de: BS " << miFactura.agua << std::endl;
                                std::cout << std::endl;
                                std::cout << "**TIPO DE CUENTA**" << std::endl;
                                std::cout << std::endl;
                                std::cout << "#1 Cuenta corriente" << std::endl;
                                std::cout << "#2 Cuenta ahorro" << std::endl;
                                std::cout << std::endl;
                                std::cout << "INGRESE LA OPCION DEL TIPO DE CUENTA PARA EL PAGO DE SERVICIO: ";
                                std::cin >> miEntrada.tipDeCue;
                                std::cout << std::endl;
                                std::cout << "INGRESE MONTO: ";
                                std::cin >> miEntrada.monto;
                                std::cout << std::endl;
                                if (miEntrada.tipDeCue == 1) {
                                    resta(miCuenta.corriente, miEntrada.monto, miFactura.agua);
                                    std::cout << "**OPERACION EXITOSA**" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de: BS " << miEntrada.monto << " desde su cuenta corriente" << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << miFactura.agua << std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El saldo actual de su cuenta corriente posterior al pago del servicio es de: BS " << miCuenta.corriente << std::endl;
                                    std::cout << std::endl;
                                } else if (miEntrada.tipDeCue == 2) {
                                    resta(miCuenta.ahorro, miEntrada.monto, miFactura.agua);
                                    std::cout << "**OPERACION EXITOSA**" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de: BS " << miEntrada.monto << " desde su cuenta de ahorro" << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << miFactura.agua << std::endl;
                                    std::cout << "*El saldo actual de su cuenta de ahorro posterior al pago del servicio es de: BS " << miCuenta.ahorro << std::endl;
                                }
                                std::cout << std::endl;
                                std::cout << "INGRESE CUALQUIER NUMERO PARA VOLVER AL MENU DE PAGOS DE SERVICIOS: ";
                                std::cin >> miEntrada.opcMenSerIf;
                            } else if (miEntrada.opcMenSer == 3) {
                                std::cout << std::endl;
                                std::cout << "**INTERNET**" <<std::endl;
                                std::cout << std::endl;
                                std::cout << "Su factura para el mes de marzo es de: BS " << miFactura.internet << std::endl;
                                std::cout << std::endl;
                                std::cout << "**TIPO DE CUENTA**" << std::endl;
                                std::cout << std::endl;
                                std::cout << "#1 Cuenta corriente" <<std::endl;
                                std::cout << "#2 Cuenta ahorro" <<std::endl;
                                std::cout << std::endl;
                                std::cout << "INGRESE EL NUMERO DEL TIPO DE CUENTA PARA EL PAGO DE SERVICIO: ";
                                std::cin >> miEntrada.tipDeCue;
                                std::cout << std::endl;
                                std::cout << "INGRESE MONTO: ";
                                std::cin >> miEntrada.monto;
                                std::cout << std::endl;
                                if (miEntrada.tipDeCue == 1) {
                                    resta(miCuenta.corriente, miEntrada.monto, miFactura.internet);
                                    std::cout << "**OPERACION EXITOSA**" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de: BS " << miEntrada.monto << " desde su cuenta corriente" << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << miFactura.internet << std::endl;
                                    std::cout << "*El saldo actual de su cuenta corriente posterior al pago del servicio es de: BS " << miCuenta.corriente << std::endl;
                                } else if (miEntrada.tipDeCue == 2) {
                                    resta(miCuenta.ahorro,  miEntrada.monto, miFactura.internet);
                                    std::cout << "**OPERACION EXITOSA**" <<std::endl;
                                    std::cout << std::endl;
                                    std::cout << "*El pago fue realizado exitosamente por un monto de " << miEntrada.monto << " desde su cuenta de ahorro" << std::endl;
                                    std::cout << "*La deuda pendiente con respecto al servicio es de: BS " << miFactura.internet << std::endl;
                                    std::cout << "*El saldo actual de su cuenta de ahorro posterior al pago del servicio es de: BS " << miCuenta.ahorro << std::endl;
                                }
                                std::cout << std::endl;
                                std::cout << "INGRESE CUALQUIER NUMERO PARA VOLVER AL MENU DE PAGOS DE SERVICIOS: ";
                                std::cin >> miEntrada.opcMenSerIf;
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
bool verifInicioSesion(entradas &entrada){
    for (int i = 0; i < 3; i++) {
        std::cout << "**INICIO DE SESION**" << std::endl;
        std::cout << std::endl;
        std::cout << "Introduzca su nombre de usuario: ";
        std::cin >> entrada.usuarioInput;
        std::cout << std::endl;
        std::cout << "Introduzca su clave: ";
        std::cin >> entrada.claveInput;
        std::cout << std::endl;
        if (entrada.usuarioInput == entrada.usuarioCto && entrada.claveInput == entrada.claveCto){
            return true;
        }
        std::cout << "Su usuario o clave son incorrectos, Intentos restantes: " << (2 - i) << std::endl;
        std::cout << std::endl;
    }
    return false;
}
void conversion(double ctaCteBs , double ctaAroBs, double &ctaCteDs, double &ctaAroDs, double tasa){
        ctaCteDs = ctaCteBs / tasa;
        ctaAroDs = ctaAroBs / tasa;
}
void transferencia (double &ctaDesc, double &ctaAum, double monto){
    ctaDesc = ctaDesc - monto;
    ctaAum = ctaAum + monto;
}
void resta(double &cuenta, double monto, double &factura){
    cuenta = cuenta - monto;
    factura = factura - monto;
}

