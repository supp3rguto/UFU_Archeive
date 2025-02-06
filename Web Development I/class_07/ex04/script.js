function calculateTax() {
    const salary = parseFloat(document.getElementById('salary').value);
    let taxRate;

    if (salary < 1903.99) {
        taxRate = 0;
    } else if (salary < 2826.66) {
        taxRate = 7.5;
    } else if (salary < 3751.06) {
        taxRate = 15;
    } else if (salary < 4664.69) {
        taxRate = 22.5;
    } else {
        taxRate = 27.5;
    }

    const result = `A alíquota do imposto de renda é ${taxRate}% do salário bruto.`;
    document.getElementById('result').innerText = result;
}