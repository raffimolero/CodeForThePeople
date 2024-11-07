function validateWith(requirements) {
  let err = '';
  for (const [key, value] of Object.entries(requirements)) {
    const isValid = value.regex.test(document.getElementById(key).value);
    if (!isValid) {
      err += `Invalid ${key}. ${value.error}\n`;
    }
  }
  if (err === '') {
    return true;
  } else {
    alert(err);
    return false;
  }
}

function validate() {
  const isValid = validateWith({
    name: {
      regex: /[A-Z][a-z]*, ([A-Z][a-z]* )+[A-Z]\./,
      error: "Must follow the format Lastname, Firstname M.",
    },
    email: {
      regex: /[\w\.]+@\w+(?:\.\w+)+/,
      error: "Must be a valid email such as johndoe@example.com.",
    },
  });
}

