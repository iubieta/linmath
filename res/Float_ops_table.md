## Operaciones con limites de float
| Operación               | Resultado esperado | Explicación breve                                                  |
| ----------------------- | ------------------ | ------------------------------------------------------------------ |
| `FLT_MAX + FLT_MAX`     | `+Inf`             | Overflow positivo, excede el rango.                                |
| `FLT_MAX + 1.0f`        | `FLT_MAX`          | El `1` es demasiado pequeño para afectar, se pierde por precisión. |
| `FLT_MAX - FLT_MAX`     | `NaN`              | Infinito menos infinito es indefinido.                             |
| `FLT_MAX - 1.0f`        | `FLT_MAX`          | Misma razón que la suma, la diferencia es insignificante.          |
| `FLT_MAX + (-FLT_MAX)`  | `NaN`              | `+Inf + -Inf` = indefinido.                                        |
| `FLT_MAX * 2.0f`        | `+Inf`             | Overflow por multiplicación.                                       |
| `-FLT_MAX + (-FLT_MAX)` | `-Inf`             | Overflow negativo.                                                 |
| `+Inf + +Inf`           | `+Inf`             | Suma de infinitos del mismo signo.                                 |
| `-Inf + -Inf`           | `-Inf`             | Suma de infinitos negativos.                                       |
| `+Inf + -Inf`           | `NaN`              | Indefinido.                                                        |
| `+Inf + número finito`  | `+Inf`             | Infinito domina.                                                   |
| `-Inf + número finito`  | `-Inf`             | Infinito domina.                                                   |
| `NaN + x`               | `NaN`              | Cualquier operación con NaN es NaN.                                |

## Comparaciones con limites de float
| Expresión         | Resultado esperado | Explicación                                 |
| ----------------- | ------------------ | ------------------------------------------- |
| `+Inf == +Inf`    | `true`             | Dos infinitos positivos son iguales.        |
| `-Inf == -Inf`    | `true`             | Dos infinitos negativos son iguales.        |
| `+Inf == -Inf`    | `false`            | Infinitos de signo distinto no son iguales. |
| `+Inf > -Inf`     | `true`             | Positivo mayor que negativo.                |
| `+Inf > FLT_MAX`  | `true`             | Infinito es mayor que cualquier finito.     |
| `-Inf < -FLT_MAX` | `true`             | -Infinito es menor que cualquier finito.    |
| `+Inf != -Inf`    | `true`             | Distintos por signo.                        |
| `+Inf != +Inf`    | `false`            | Iguales.                                    |
| `NaN == NaN`      | `false`            | NaN nunca es igual a nada, ni a sí mismo.   |
| `NaN != NaN`      | `true`             | Por definición IEEE-754.                    |
| `NaN < x`         | `false`            | Comparación con NaN siempre es falsa.       |
| `NaN > x`         | `false`            | Ídem.                                       |
| `NaN == x`        | `false`            | Ídem.                                       |
| `isnan(NaN)`      | `true`             | Función de `<math.h>` para detectar NaN.    |
| `isinf(+Inf)`     | `true`             | Detecta infinito.                           |
| `isinf(FLT_MAX)`  | `false`            | `FLT_MAX` aún es finito.                    |

