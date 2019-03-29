    var code, tag, links

    var question = $('#question-title').textContent.trim()

    var difficulty = $('div.css-10o4wqw > div').textContent.trim()

    var description = $('div.darker-content__naal > div').textContent.trim()

    code = ""
    var lines=$('div.CodeMirror-code').children
    for (i = 0; i < lines.length; i ++) {
        code += lines[i].children[1].textContent + '\n'
    }

    tag = "Difficulty:" + difficulty
    /*var tags=$('#desktop-side-bar > div > ul > li')
    for (i = 0; i < tags.length && i < 3; i ++) {
        tag += tags[i].textContent + '\n'
    }*/

    link = ""
    /*var misc = $('#desktop-side-bar > div > ul > li.list-item-tags > div.tags > #all-tags > div.tag-section')
    for (i = 0; i < misc.length; i ++) {
        if (i < 2) {
            link += misc[i].textContent.trim().replace(/\s+/g, ' ') + '\n'
        } else {
            link += misc[i].textContent.trim()
        }
    }*/

    function downloadContent(filename, text) {
      var element = document.createElement('a');
      element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
      element.setAttribute('download', filename);

      element.style.display = 'none';
      document.body.appendChild(element);

      element.click();

      document.body.removeChild(element);
    }

    downloadContent(question + '.c',
                    '\/*\n' + question    + '\n\n' +
                              description +
                    '\n*\/\n\n' +
                    code + '\n\n' +
                    '/\*\n' + tag         + '\n\n' +
                              link        +
                    '\n*\/\n')
