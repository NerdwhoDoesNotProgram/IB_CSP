from flask import Flask, redirect, url_for, render_template

app = Flask(__name__)
admin = True

@app.route('/')
def home():
    return render_template('index.html', title='Home Page', content='Welcome to the home page!')

@app.route('/test')
def testing():
    return render_template('index.html', title='Testing Page', content='This is just the testing page!')
@app.route('/admin')
def administrator():
    if admin:
        return render_template('basic.html', title='Admin Page', content='Welcome, admin!')
    else:
        return redirect(url_for('home'))

@app.route('/<name>')
def person(name):
    return f"<h1>Hello, {name}!</h1><p>Welcome to the Flask page!</p>"



app.run()