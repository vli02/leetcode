    var code, tag, links

    var question = $('h3')[0].textContent.trim()

    var difficulty = $('span.pull-right.difficulty-label.round.label')[0].textContent

    var description = $('div.question-description')[0].textContent.trim()

    code = ""
    var lines=$('pre.CodeMirror-line')
    for (i = 1; i < lines.length; i ++) {
        code += lines[i].textContent + '\n'
    }

    tag = ""
    var tags=$('#desktop-side-bar > div > ul > li')
    for (i = 0; i < tags.length && i < 3; i ++) {
        tag += tags[i].textContent + '\n'
    }

    link = ""
    var misc = $('#desktop-side-bar > div > ul > li.list-item-tags > div.tags > #all-tags > div.tag-section')
    for (i = 0; i < misc.length; i ++) {
        if (i < 2) {
            link += misc[i].textContent.trim().replace(/\s+/g, ' ') + '\n'
        } else {
            link += misc[i].textContent.trim()
        }
    }

    function downloadContent(name, content) {
        var atag = document.createElement("a");
        var file = new Blob([content], {type: 'text/plain'});
        atag.href = URL.createObjectURL(file);
        atag.download = name;
        atag.click();
    }

    downloadContent(question + '.c',
                    '\/*\n' + question    + '\n\n' +
                              description +
                    '\n*\/\n\n' +
                    code + '\n\n' +
                    '/\*\n' + tag         + '\n\n' +
                              link        +
                    '\n*\/\n')
