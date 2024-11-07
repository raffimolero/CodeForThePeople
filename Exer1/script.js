function validateWith(requirements) {
  let err = '';
  for (const [key, value] of Object.entries(requirements)) {
    const isValid = value.regex.test(document.getElementById(key).value);
    if (!isValid) {
      err += `Invalid ${key}: ${value.error}\n`;
    }
  }
  return err;
}

function validate() {
  const err = validateWith({
    name: {
      regex: /[A-Z][a-z]*, ([A-Z][a-z]* )+[A-Z]\./,
      error: "Must follow the format Lastname, Firstname M.",
    },
    email: {
      regex: /[\w\.]+@\w+(?:\.\w+)+/,
      error: "Must be a valid email like name@example.com",
    },
  });
  if (err === '') {
    alert('Registered.');
  } else {
    alert('Failed to register:\n\n' + err);
  }
}
